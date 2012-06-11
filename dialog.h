#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

#include <QUdpSocket>
#include <QTimer>

#include "Mavlink/custom_mavlink_messages/mavlink.h"

#define BUFFER_LENGTH 2041

namespace Ui {
    class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    Ui::Dialog *ui;
    QUdpSocket *udpSocket;
    QUdpSocket *udpSocketFromQGroundControl;
    QHostAddress *host;
    QTimer *timer;

    //mavlink:
    mavlink_message_t msg;
    mavlink_manual_control_t* manual_control;
    uint16_t len;
    uint8_t buf[BUFFER_LENGTH];


private slots:
    void on_pushButton_clicked();
    void on_pbStartSimuMavlink_clicked();
    void startBroadcasting();
    void broadcastDatagram();
    void processPendingDatagrams();
};

#endif // DIALOG_H
