#include "serverdialog.h"
#include "ui_serverdialog.h"

ServerDialog::ServerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ServerDialog)
{
    ui->setupUi(this);
}

ServerDialog::~ServerDialog()
{
    delete ui;
}
//创建服务器按钮对应的槽函数
void ServerDialog::on_pushButton_clicked()
{
    //获取服务器端口
    serverPort=ui->lineEdit->text().toShort();//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆
    //设置监听服务器IP和端口
    bool res = tcpServer.listen(
           QHostAddress::Any,serverPort);//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆
    if(res == false){
        qDebug("创建服务器失败!");
        return;
    }
    qDebug("创建服务器成功!");
    //禁用创建按钮和端口输入
    ui->pushButton->setEnabled(false);
    ui->lineEdit->setEnabled(false);
    //当客户端和服务器建立连接,发送信号newConnection
    connect(&tcpServer,SIGNAL(newConnection()),
            this,SLOT(onNewConntion()));//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆
}
//响应客户端连接请求的槽函数
void ServerDialog::onNewConntion()
{
    //获取和客户端通信套接字
    QTcpSocket* clientSocket =
        tcpServer.nextPendingConnection();//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆
    //保存和客户端通信套接字到容器
    tcpClientList.append(clientSocket);//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆
    //当客户端给服务器发送消息时,发送信号readyRead
    connect(clientSocket,SIGNAL(readyRead()),
        this,SLOT(onReadyRead()));//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆
}
//接收客户端聊天消息的槽函数
void ServerDialog::onReadyRead()
{
    //遍历检查容器中保存的和客户端通信套接字是否已经
    //断开连接,如果已经断开则剔除.
    for(int i=0;i<tcpClientList.size();i++){
        if(tcpClientList.at(i)->state() ==
            QAbstractSocket::UnconnectedState){
            tcpClientList.removeAt(i);
            --i;
        }
    }

    //遍历容器中所有客户端通信的套接字
    for(int i=0;i<tcpClientList.size();i++){
        //如果第i个套接字有消息返回结果大于0,否则为0
        if(tcpClientList.at(i)
                ->bytesAvailable()){
            //读取第i个套接字发来的消息
            QByteArray buf=
                tcpClientList.at(i)->readAll();//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆
            //显示消息
            ui->listWidget->addItem(buf);//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆
            ui->listWidget->scrollToBottom();
            //转发消息给其它客户端
            sendMessage(buf);//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆
        }
    }
}
//转发聊天消息的函数
void ServerDialog::sendMessage(
        const QByteArray& msg)
{
    //将聊天消息转发给所有客户端(群聊)
    for(int i=0;i<tcpClientList.size();i++){
        tcpClientList.at(i)->write(msg);//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆
    }
}




