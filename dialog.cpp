#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    timer = new QTimer();
    udpSocket = new QUdpSocket(this);
    host = new QHostAddress("127.0.0.1");

    udpSocketFromQGroundControl = new QUdpSocket(this);
    udpSocketFromQGroundControl->bind(14551);//, QUdpSocket::ShareAddress);

    //connect(ui->pbStartSimuMavlink,SIGNAL(clicked()),this,SLOT(startBroadcasting()));
    connect(timer, SIGNAL(timeout()), this, SLOT(broadcastDatagram()));
    connect(udpSocketFromQGroundControl, SIGNAL(readyRead()),this, SLOT(processPendingDatagrams()));

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pbStartSimuMavlink_clicked()
{
    qDebug()<<"[Dialog] - on_pbStartSimuMavlink_clicked()!";
    timer->start(1000);
}

//private slots:
void Dialog::startBroadcasting()
{
    timer->start(1000);
}

//private slots:
void Dialog::broadcastDatagram()
{
static int num = 0;
num++;
    //qDebug()<<"broadcast"<<endl;


    mavlink_msg_heartbeat_pack(100, 200, &msg, MAV_TYPE_GENERIC, MAV_AUTOPILOT_GENERIC,0,0,0);
    len = mavlink_msg_to_send_buffer(buf, &msg);
    udpSocket->writeDatagram((char*)buf,len, *host, 14550);
    //ui->textEdit->setText((char *)buf);
    QString strNum = QString().setNum(num);
    QString strMsgId = QString().setNum(msg.msgid);
    QString *str = new QString("Sent No: ");//<< msg.sysid <<"COMP:"<<msg.compid<<"LEN:"<<msg.len<<"MSG ID:"<<msg.msgid);
    str->append(strNum);
    str->append(" MSG ID : ");
    str->append(strMsgId);
    ui->textEditSendMessage->setText(*str);


//    mavlink_msg_sys_status_pack(2, 200, &msg, MAV_MODE_MANUAL, MAV_NAV_HOLD, MAV_STATE_ACTIVE, 750, 12300,0,0);
//    len = mavlink_msg_to_send_buffer(buf, &msg);
//    udpSocket->writeDatagram((char*)buf,len, *host, 14550);

    //mavlink_msg_manual_control_decode(&msg, manual_control);


//    QHostAddress host = QHostAddress("127.0.0.1");
//    messageNo++;
//    QByteArray datagram = "Broadcast message " + QByteArray::number(messageNo);
//    udpSocket->writeDatagram(datagram.data(), datagram.size(),host, 14550);
}

void Dialog::processPendingDatagrams()
{
    mavlink_message_t msg;
    mavlink_status_t status;

    while (udpSocketFromQGroundControl->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(udpSocketFromQGroundControl->pendingDatagramSize());
        udpSocketFromQGroundControl->readDatagram(datagram.data(), datagram.size());
        ui->textEdit->setText(tr("Received (%1) bytes datagram: \"%2\"")
                .arg(datagram.size())
                .arg(datagram.data()));

        for (int i=0; i<datagram.size();i++)
        {
            if (mavlink_parse_char(MAVLINK_COMM_0,datagram.at(i),&msg,&status))
                qDebug()<<"Received packet: SYS:"<< msg.sysid <<"COMP:"<<msg.compid<<"LEN:"<<msg.len<<"MSG ID:"<<msg.msgid<<endl;
                //qDebug()<<"msg: "<< msg.payload<<endl;
//            switch (msg.msgid)
//            {
//                case ""
//            }
        }


    }
}

void Dialog::on_pushButton_clicked()
{

    mavlink_msg_attitude_pack (100, 200, &msg, 47, 0.1, 0.2, 0.3, 0, 0, 0) ;
    len = mavlink_msg_to_send_buffer(buf, &msg);
    udpSocket->writeDatagram((char*)buf,len, *host, 14550);
    //ui->textEdit->setText((char *)buf);
//    QString strNum = QString().setNum(num);
//    QString strMsgId = QString().setNum(msg.msgid);
//    QString *str = new QString("Sent No: ");//<< msg.sysid <<"COMP:"<<msg.compid<<"LEN:"<<msg.len<<"MSG ID:"<<msg.msgid);
//    str->append(strNum);
//    str->append(" MSG ID : ");
//    str->append(strMsgId);
//    ui->textEditSendMessage->setText(*str);

}
