#include "senderdialog.h"
#include "ui_senderdialog.h"

SenderDialog::SenderDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SenderDialog)
{
    ui->setupUi(this);
    isStarted = false;//停止广播*****************************************
    udpSocket = new QUdpSocket(this);//*****************************************
    timer = new QTimer(this);//*****************************************
    //定时器到时将发送信号timeout
    connect(timer,SIGNAL(timeout()),
            this,SLOT(sendMessage()));//*****************************************
}
SenderDialog::~SenderDialog()
{
    delete ui;
}
//开始广播按钮的槽函数
void SenderDialog::on_pushButton_clicked()
{
    if(isStarted == false){
        isStarted = true;//开始广播
        //修改按钮文本:"停止广播"
        ui->pushButton->setText("停止广播");
        //禁用消息和端口的输入
        ui->messageEdit->setEnabled(false);
        ui->portEdit->setEnabled(false);
        //开启定时器,每隔1000毫秒广播一次
        timer->start(1000);//*****************************************
    }
    else{
        isStarted = false;//停止广播
        ui->pushButton->setText("开始广播");
        ui->messageEdit->setEnabled(true);
        ui->portEdit->setEnabled(true);
        timer->stop();//关闭定时器//*****************************************
    }
}
//定时发送广播消息的槽函数
void SenderDialog::sendMessage()
{
    //获取广播端口
    quint16 port=ui->portEdit->text().toShort();//*****************************************
    //获取广播消息
    QString msg=ui->messageEdit->text();//*****************************************
    if(msg == ""){
        return;
    }
    //发送关闭消息
    //参数:消息内容(QByteArray),IP,端口
    //toUtf8():QString转换QByteArray
    udpSocket->writeDatagram(msg.toUtf8(),
        QHostAddress::Broadcast,port);//*****************************************
}







