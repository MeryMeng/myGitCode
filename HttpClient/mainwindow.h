#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QAuthenticator>//验证登录
#include <QFile>
#include <QFileInfo>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    //处理菜单选项的槽函数
    void onTriggered(QAction* action);
private:
    //向服务器发送请求
    void sendRequest();
private slots:
    //验证登录的槽函数
    void onAuthenticationRequired(
        QNetworkReply*,QAuthenticator*);
    //接收响应数据的槽函数
    void onReadyRead(void);
    //接收响应数据结束时执行的槽函数
    void onFinished(void);

    //处理目录链接的槽函数
    void onAnchorClicked(const QUrl&);

private:
    //发送下载文件的请求
    void downloadFile(const QUrl& fileUrl);
private slots:
    //接收文件内容的槽函数
    void receiveFile();
    //表示文件下载进度的槽函数
    void onDownloadProgress(qint64,qint64);
    //文件下载完成执行的槽函数
    void receiveFileFinish();

private:
    Ui::MainWindow *ui;
    QNetworkAccessManager* manager;//管理通信过程
    QNetworkRequest request;//请求
    QNetworkReply* reply;//响应
    QUrl currentUrl;//记录当前Url地址
    QByteArray buf;//保存响应数据
    QFile* file;//用于保存要下载的文件
};

#endif // MAINWINDOW_H






