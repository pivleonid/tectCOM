#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QTextCodec>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    const QList<QSerialPortInfo> infos = QSerialPortInfo::availablePorts();
    QStringList ports;

    for (const QSerialPortInfo &info : infos) {
        ports.append(info.portName());
        ui->serialPortInfoBox->addItem(info.portName());

    }

    port = new QSerialPort(this);
    connect(ui->connectBtn, SIGNAL(clicked(bool)), this, SLOT(transmitConnect()));
    connect(ui->disconnectBtn, SIGNAL(clicked(bool)), this, SLOT(transmitDisconnect()));
    connect(ui->sendBtn, SIGNAL(clicked(bool)), this, SLOT(transmitSend()));


    connect(port, &QSerialPort::readyRead, this, &MainWindow::readData);

    int i;
    i++;
}

MainWindow::~MainWindow()
{
    delete ui;
    delete port;
}


void MainWindow::transmitSend(){
    QByteArray data;
    QString str =  ui->lineEdit->text();
    for(int i = 0; i < str.count(); i++)
        data.append(str.at(i));
    port->write(data);

}

void MainWindow::transmitConnect(){

    port->setPortName(ui->serialPortInfoBox->currentText());
    port->setBaudRate(ui->boudrateBox->currentText().toInt());
    port->setDataBits(QSerialPort::Data8);
    port->setParity(QSerialPort::NoParity);
    port->setStopBits(QSerialPort::OneStop);
    port->setFlowControl(QSerialPort::NoFlowControl);
    if (port->open(QIODevice::ReadWrite)) {

    } else {
        QMessageBox::critical(this, tr("Error"), port->errorString());

        //showStatusMessage(tr("Open error"));
    }

}
void MainWindow::transmitDisconnect(){
    if (port->isOpen())
        port->close();
}

void MainWindow::readData(){
    QByteArray data = port->readAll();
    QTextCodec* codec =  QTextCodec::codecForName("cp-866");
    QString fio = codec->toUnicode(data.data());
    ui->textEdit->insertPlainText(fio);
}
