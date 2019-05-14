#ifndef SERVERDIALOG_H
#define SERVERDIALOG_H

#include <QDialog>
#include <QTcpServer>//QT+=network
#include <QTcpSocket>
#include <QDebug>

namespace Ui {
class ServerDialog;
}

class ServerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ServerDialog(QWidget *parent = 0);
    ~ServerDialog();

private slots:
    //创建服务器按钮对应的槽函数
    void on_pushButton_clicked();//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆
    //响应客户端连接请求的槽函数
    void onNewConntion();//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆
    //接收客户端聊天消息的槽函数
    void onReadyRead();//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆
private:
    //转发聊天消息的函数
    void sendMessage(const QByteArray&);//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆
private:
    Ui::ServerDialog *ui;
    QTcpServer tcpServer;//tcp服务器 ☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆
    quint16 serverPort;//服务器端口☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆
    //保存和客户端通信的套接字容器
    QList<QTcpSocket*> tcpClientList;//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆
};

#endif // SERVERDIALOG_H



