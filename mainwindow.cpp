#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QTextCodec>
#include <QByteArray>
#include <QBitArray>
#include <QDesktopWidget>
#include <QSettings>

#include <QDebug>




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QDesktopWidget* pwdg = QApplication::desktop();
    move(pwdg->width()/2-width()/2, pwdg->height()/2-height()/2);

#ifdef LINUXBASE
    QTextCodec* codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForTr(codec);
    ui->serialPortInfoBox->addItem("COM1");
    ui->serialPortInfoBox->addItem("COM2");
#endif


#ifndef LINUXBASE

const QList<QSerialPortInfo> infos = QSerialPortInfo::availablePorts();
QStringList ports;
for (const QSerialPortInfo &info : infos) {
   ports.append(info.portName());
   ui->serialPortInfoBox->addItem(info.portName());
}
port = new QSerialPort(this);
connect(port, &QSerialPort::readyRead, this, &MainWindow::readData);
#endif

    connect(ui->connectBtn, SIGNAL(clicked(bool)), this, SLOT(transmitConnect()));
    connect(ui->disconnectBtn, SIGNAL(clicked(bool)), this, SLOT(transmitDisconnect()));
    connect(ui->startBtn, SIGNAL(clicked(bool)), this, SLOT(transmitStart()));
    connect(ui->stopBtn, SIGNAL(clicked(bool)), this, SLOT(transmitStop()));
    connect(ui->hightBtn, SIGNAL(clicked(bool)), this, SLOT(putSlotData()));
    connect(ui->lowBtn,SIGNAL(clicked(bool)),this, SLOT(putSlotData()));
    connect(ui->ClearBtn,SIGNAL(clicked(bool)), this, SLOT(clearData()));
    tmr = new QTimer();
    connect(tmr, SIGNAL(timeout()), this, SLOT(transmitSend()));
    ui->startBtn->setEnabled(false);
    ui->stopBtn->setEnabled(false);





    QRegExp codeReg("[0-1]{1,}");
QRegExpValidator *ipValidator = new QRegExpValidator(codeReg, this);
ui->lineEdit->setValidator(ipValidator);
QRegExp codeReg1("[0-9]{1,10}");
QRegExpValidator *ipValidator1 = new QRegExpValidator(codeReg1, this);
ui->timerLE->setValidator(ipValidator1);


QSettings settings( "testCOM.conf", QSettings::IniFormat );
settings.beginGroup( "saveState" );

ui->boudrateBox->setCurrentText(settings.value("boudrateBox").toString());
ui->lineEdit->setText(settings.value("lineEdit").toString());
ui->timerLE->setText(settings.value("timerLE").toString());
settings.endGroup();


//Подсказки
ui->serialPortInfoBox->setToolTip("Выбор COM порта");
ui->boudrateBox->setToolTip("Выбор скорости передачи данных");
ui->lineEdit->setToolTip("Битовая последовательность. \nСтарший байт слева.");
ui->startBtn->setToolTip("Начало тестирования");
ui->stopBtn->setToolTip("Остановка тестирования");
ui->timerLE->setToolTip("Установка таймера");
}

void MainWindow::transmitStart(){
    ui->startBtn->setEnabled(false);
    ui->stopBtn->setEnabled(true);
     QString str = ui->lineEdit->text();
    int n = str.count();
    // ежели битов меньше 8 - добавляю нули
    if(n<= 8){
       int k = 8 - n;
       for(int i = 0; i < k; i++)
        str.append('0');
    }
    if(n > 8){
        int k = 8 - (n % 8);
        for(int i = 0; i < k; i++)
         str.append('0');
    }
    QBitArray dataBit;//(str.count);
    dataBit.resize(str.count());
    //формирую массив битов
    for(int i = 0; i < dataBit.count(); i++){
        if(str[i] == '0')
            dataBit.setBit(i, false);
        if(str[i] == '1')
            dataBit.setBit(i, true);
    }
    // операция зеркалит данные dataByte[i/8] = (dataByte.at(i/8) | ((dataBit[i] ? 1 : 0) << (i % 8)));
    QBitArray temp(1);
    int c = dataBit.size();
    for(int i = 0; i < dataBit.size()/2; i++){
       temp[0] =  dataBit[i];
       dataBit[i] = dataBit[dataBit.size() - i - 1];
       dataBit[dataBit.size() - i -1] = temp[0];
    }
    dataByte.clear();
    dataByte.resize(dataBit.size()/ 8);
    for(int i = 0; i < dataByte.size(); i++)
        dataByte[i] = 0x00;
    for(int i = 0; i < dataBit.size(); i++)
        dataByte[i/8] = (dataByte.at(i/8) | ((dataBit[i] ? 1 : 0) << (i % 8)));
    //меняю местаами байты
   QByteArray invers;
   for(int i = 0; i < dataByte.count(); i++){
    if( dataByte.count() == 1){
        tmr->start(ui->timerLE->text().toInt());
        return;
    }
    invers[i] = dataByte[dataByte.count() -1 - i];

   }
    dataByte.clear();
    dataByte = invers;
    tmr->start(ui->timerLE->text().toInt());


}

void MainWindow::transmitStop(){

    tmr->stop();
    ui->startBtn->setEnabled(true);
    ui->stopBtn->setEnabled(false);
}

void MainWindow::clearData(){
    ui->lineEdit->clear();
}

void MainWindow::putSlotData(){

    QObject* obj = QObject::sender();
    QPushButton* btn = dynamic_cast<QPushButton*> (obj);
    QString str  = btn->text();
    if( str.indexOf('0') >= 0){
        ui->lineEdit->insert("0");
        return;
    }
    if( str.indexOf('1') >= 0)
        ui->lineEdit->insert("1");
}

MainWindow::~MainWindow()
{
    delete ui;
    delete tmr;
#ifndef LINUXBASE
delete port;
#endif
}


void MainWindow::transmitSend(){
#ifdef LINUXBASE
    char* data;
    data = dataByte.data();
    int iOut = write(fd, data, dataByte.count());
#endif
#ifndef LINUXBASE
port->write(dataByte);
#endif
}

void MainWindow::transmitConnect(){
#ifdef LINUXBASE
QString port = ui->serialPortInfoBox->currentText();
    if( port == "COM1")
        fd = open("/dev/ttyS1", O_RDWR | O_NOCTTY );
    if(port == "COM2")
         fd = open("/dev/ttyS2", O_RDWR | O_NOCTTY );
    if(fd < 0){
        QMessageBox msb;
        msb.setWindowTitle("Error");
        msb.setText("Error opening port");
        msb.exec();
    }
   if(fd > 0)
        ui->startBtn->setEnabled(true);

    struct termios term;
    tcgetattr(fd, &term);
    int brate = ui->boudrateBox->currentText().toInt();
    if(brate == 1200)
        cfsetispeed(&term, B1200);
    if(brate == 2400)
        cfsetispeed(&term, B2400);
    if(brate == 4800)
        cfsetispeed(&term, B4800);
    if(brate == 9600)
        cfsetispeed(&term, B9600);
    if(brate == 19200)
        cfsetispeed(&term, B19200);
    if(brate == 38400)
        cfsetispeed(&term, B38400);
    if(brate == 57600)
        cfsetispeed(&term, B57600);
    if(brate == 115200)
        cfsetispeed(&term, B115200);
    tcsetattr(fd, TCSANOW, &term);
#endif
#ifndef LINUXBASE

    port->setPortName(ui->serialPortInfoBox->currentText());
    port->setBaudRate(ui->boudrateBox->currentText().toInt());
    port->setDataBits(QSerialPort::Data8);
    port->setParity(QSerialPort::NoParity);
    port->setStopBits(QSerialPort::OneStop);
    port->setFlowControl(QSerialPort::NoFlowControl);
    if (port->open(QIODevice::ReadWrite)) {
    } else {
        QMessageBox::critical(this, tr("Error"), port->errorString());
    }
    ui->startBtn->setEnabled(true);
    ui->connectBtn->setEnabled(false);
     ui->disconnectBtn->setEnabled(true);
#endif

}
void MainWindow::
transmitDisconnect(){
#ifndef LINUXBASE
    if (port->isOpen())
        port->close();
#endif
#ifdef LINUXBASE
    if(tmr->isActive())
        transmitStop();
    func(fd);
#endif
    ui->startBtn->setEnabled(true);
    ui->stopBtn->setEnabled(false);
    ui->connectBtn->setEnabled(true);
     ui->disconnectBtn->setEnabled(false);
}

void MainWindow::readData(){
#ifndef LINUXBASE
    QByteArray data = port->readAll();
    QTextCodec* codec =  QTextCodec::codecForName("cp-866");
    QString fio = codec->toUnicode(data.data());

#endif
}


#ifdef LINUXBASE
void func(int fd){
    close(fd);
}
#endif


void MainWindow::closeEvent(QCloseEvent* event){

    QSettings settings( "testCOM.conf", QSettings::IniFormat );
    settings.beginGroup( "saveState" );
    settings.setValue( "boudrateBox", ui->boudrateBox->currentText() );
    settings.setValue( "lineEdit",   ui->lineEdit->text() );
    settings.setValue( "timerLE",   ui->timerLE->text() );
    settings.endGroup();
}


