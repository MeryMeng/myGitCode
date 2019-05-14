#include "clientdialog.h"
#include "ui_clientdialog.h"

ClientDialog::ClientDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClientDialog)
{
    ui->setupUi(this);
    status = false;//初始化离线状态
    //和服务器连接成功时发送信号connected
    connect(&tcpSocket,SIGNAL(connected()),
            this,SLOT(onConnected()));//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆
    //和服务器断开连接时发送信号disconnected
    connect(&tcpSocket,SIGNAL(disconnected()),
            this,SLOT(onDisconnected()));
    //收到服务器转发的聊天消息时发送信号readyRead
    connect(&tcpSocket,SIGNAL(readyRead()),
            this,SLOT(onReadyRead()));//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆
    //网络异常时发送信号:error
    connect(&tcpSocket,SIGNAL(error(
        QAbstractSocket::SocketError)),
            this,SLOT(onError()));
}

ClientDialog::~ClientDialog()
{
    delete ui;
}
//发送消息按钮对应的槽函数
void ClientDialog::on_sendButton_clicked()
{
    //获取用户输入的聊天消息
    QString msg = ui->messageEdit->text();//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆
    if(msg == ""){
        return;
    }
    msg = username + ":" + msg;
    //发送消息
    tcpSocket.write(msg.toUtf8());//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆
    //清空消息输入框
    ui->messageEdit->clear();
}
//连接服务器按钮对应的槽函数
void ClientDialog::on_connectButton_clicked()
{
    //如果当前是离线状态则建立连接
    if(status == false){
        //获取服务器IP
        QString ip = ui->serverIpEdit->text();//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆
        if(serverIp.setAddress(ip) == false){
            //如果设置IP地址错误,弹出消息提示框
            QMessageBox::critical(
                this,"Error","IP地址格式错误!");
            return;
        }
        //获取服务器端口
        serverPort = ui->serverPortEdit->text(
                    ).toShort();//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆
        if(serverPort < 1024){
            //如果设置端口错误,弹出消息提示框
            QMessageBox::critical(
                this,"Error","端口格式错误!");
            return;
        }
        //获取聊天室昵称
        username = ui->usernameEdit->text();//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆
        if(username == ""){
            //如果聊天室昵称为空,弹出消息提示框
            QMessageBox::critical(
                this,"Error","用户昵称不能为空!");
            return;
        }
        //向服务器发送连接请求:
        //如果连接成功发送信号:connected
        //如果连接失败发送信号:error
        tcpSocket.connectToHost(
                    serverIp,serverPort);//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆
    }
    //如果当前是在线状态则断开连接
    else{
        //向服务器发送离开聊天室提示消息
        QString msg = username + ":离开聊天室!";
        tcpSocket.write(msg.toUtf8());
        //断开和服务器连接,同时发送信号disconnected
        tcpSocket.disconnectFromHost();//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆
    }
}
//和服务器连接成功时执行的槽函数
void ClientDialog::onConnected(void)
{
    status = true;//标记客户端在线状态
    //使能发送消息按钮
    ui->sendButton->setEnabled(true);
    //禁用:ip,port,username输入
    ui->serverIpEdit->setEnabled(false);
    ui->serverPortEdit->setEnabled(false);
    ui->usernameEdit->setEnabled(false);
    //修改按钮文本为:"离开聊天室"
    ui->connectButton->setText("离开聊天室");
    //向服务器发送进入聊天室提示消息
    QString msg=username +":进入了聊天室!";//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆
    //toUtf8():QString转换QByteArray
    tcpSocket.write(msg.toUtf8());//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆
}
//和服务器断开连接时执行的槽函数
void ClientDialog::onDisconnected(void)
{
    status = false;//标记为离线状态
    //禁用发送消息按钮
    ui->sendButton->setEnabled(false);
    //恢复ip,port,username输入
    ui->serverIpEdit->setEnabled(true);
    ui->serverPortEdit->setEnabled(true);
    ui->usernameEdit->setEnabled(true);
    //修改按钮文本为:"连接服务器"
    ui->connectButton->setText("连接服务器");
}
//接收聊天消息的槽函数
void ClientDialog::onReadyRead(void)
{
    //判断接收的消息字节数是否大于0
    if(tcpSocket.bytesAvailable()){
        //读取消息并保存
        QByteArray buf=tcpSocket.readAll();//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆
        //显示聊天消息
        ui->listWidget->addItem(buf);//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆
        ui->listWidget->scrollToBottom();
    }
}
//网络异常时执行的槽函数
void ClientDialog::onError(void)
{
    //提示网络异常原因
    //errorString:获取网络异常原因的字符串
    QMessageBox::critical(
        this,"Error",tcpSocket.errorString());
}









