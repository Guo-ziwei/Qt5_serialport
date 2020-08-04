#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTextEdit>
#include <QRadioButton>
//#include <sys/gpiofd.h>
#include <sys/select.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <QtSerialPort/QSerialPort>
#include <QSerialPortInfo>
#include <QThread>

namespace Ui {
class Widget;
class MyThread;
}

class MyThread:  public QThread
{
    Q_OBJECT

public:
    MyThread();
    void run();
signals:
    void send(int num);

};

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:

   void on_LED_toggled(bool checked);

   void on_LED_1_toggled(bool checked);

   void on_LED_2_toggled(bool checked);

   void on_LED_3_toggled(bool checked);

   void on_LED_4_toggled(bool checked);

   void on_LED_5_toggled(bool checked);

   void on_LED_6_toggled(bool checked);

   void on_LED_7_toggled(bool checked);

   void on_uart_open_clicked();

   void on_uart_num_currentIndexChanged(const QString &arg1);

   void on_uart_baud_currentIndexChanged(const QString &arg1);

   void on_uart_close_clicked();

   void readData();

   void writeData();

   void lcdnumberValset(int num);

   void on_uart_search_clicked();

private:
    Ui::Widget *ui;
    QSerialPort *serial;
    QTextEdit *receive_box;
    QRadioButton *LED1;
};

#endif // WIDGET_H
