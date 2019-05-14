#ifndef SENDERDIALOG_H
#define SENDERDIALOG_H

#include <QDialog>
#include <QUdpSocket>//QT += network
#include <QTimer>

namespace Ui {
class SenderDialog;
}

class SenderDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SenderDialog(QWidget *parent = 0);
    ~SenderDialog();

private slots:
    //开始广播按钮的槽函数
    void on_pushButton_clicked();//*****************************************
    //定时发送广播消息的槽函数
    void sendMessage();//*****************************************
private:
    Ui::SenderDialog *ui;
    bool isStarted;//标记:广播开始/广播停止 *****************************************
    QUdpSocket* udpSocket;//UDP套接字 *****************************************
    QTimer* timer;//定时器 *****************************************
};

#endif // SENDERDIALOG_H









