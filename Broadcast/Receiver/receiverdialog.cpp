#include "receiverdialog.h"
#include "ui_receiverdialog.h"

ReceiverDialog::ReceiverDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReceiverDialog)
{
    ui->setupUi(this);
    isStarted = false;//停止接收*****************************************
    udpSocket = new QUdpSocket(this);//*****************************************
}

ReceiverDialog::~ReceiverDialog()
{
    delete ui;
}
//开始接收按钮对应的槽函数
void ReceiverDialog::on_pushButton_clicked()
{
    if(isStarted == false){
        isStarted = true;//开始接收
        //修改按钮文本
        ui->pushButton->setText("停止接收");
        //禁用端口输入
        ui->lineEdit->setEnabled(false);
        //获取端口号
        quint16 port =
            ui->lineEdit->text().toShort();//*****************************************
        //绑定IP(默认Any)和端口
        if(udpSocket->bind(port)==false){
            qDebug() << "bind失败!";//*****************************************
        }
        //当广播消息到来,发送信号readyRead()
        connect(udpSocket,SIGNAL(readyRead()),
                this,SLOT(messageReceived()));//*****************************************
    }
    else{
        isStarted = false;//停止接收
        //修改按钮文本
        ui->pushButton->setText("开始接收");
        //恢复端口输入
        ui->lineEdit->setEnabled(true);
        //关闭套接字
        udpSocket->close();//*****************************************
    }
}
//接收广播消息的槽函数
void ReceiverDialog::messageReceived()
{
    //判断udp是否等到读取的数据包
    if(udpSocket->hasPendingDatagrams()){
        //准备接收数据包的缓冲区
        QByteArray buf;//*****************************************
        //设置缓冲区和等待读取数据包的大小一致
        buf.resize(
            udpSocket->pendingDatagramSize());//*****************************************
        //读取数据
        //参数:缓冲区首地址(char*),接收数据包大小
        //data():QByteArray转换char*
        udpSocket->readDatagram(
                    buf.data(),buf.size());//*****************************************
        //显示广播消息
        ui->listWidget->addItem(buf);//*****************************************
        //回滚显示最底部的消息(最新消息)
        ui->listWidget->scrollToBottom();
    }
}









