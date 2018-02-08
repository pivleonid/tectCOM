#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>



#include <QList>
#include <QTimer>
#include <QProcess>

#ifndef LINUXBASE
#include <QSerialPortInfo>
#include <QSerialPort>
#endif

#ifdef LINUXBASE
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#endif




namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTimer* tmr;
    QByteArray dataByte;
    QProcess listRS232;
    int fd;
    bool timer;
#ifndef LINUXBASE
    QSerialPort* port;
#endif
public slots:
    void transmitSend();
    void transmitDisconnect();
    void transmitConnect();
    void readData();
    void putSlotData();
    void clearData();
    void transmitStop();
    void transmitStart();
};


#endif // MAINWINDOW_H
