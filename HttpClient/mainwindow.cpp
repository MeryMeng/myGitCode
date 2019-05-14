#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //点击菜单选项时发送信号triggered
    connect(ui->menuBar,SIGNAL(
                triggered(QAction*)),
            this,SLOT(onTriggered(QAction*)));

    //创建管理通信过程的Manager对象
    manager = new QNetworkAccessManager(this);
    //初始化请求
    request.setUrl(
        QUrl("http://code.tarena.com.cn/"));
    //向服务器发送请求
    sendRequest();

    //点击目录链接时发送信号:anchorClicked
    connect(ui->textBrowser,
            SIGNAL(anchorClicked(QUrl)),
            this,SLOT(onAnchorClicked(QUrl)));

}
MainWindow::~MainWindow()
{
    delete ui;
}
//处理菜单选项的槽函数
void MainWindow::onTriggered(QAction *action)
{
    //在状态栏显示菜单选项
    ui->statusBar->showMessage(action->text());
    if(action->text() == "Full"){
        showFullScreen();//窗口全屏
    }
    else if(action->text() == "Normal"){
        showNormal();//恢复窗口大小
    }
}

//向服务器发送请求
void MainWindow::sendRequest()
{
    //发送请求,返回用于接收响应数据的reply对象
    reply = manager->get(request);
    //如果请求访问的服务器需要认证,将发送认证信号
    connect(manager,
        SIGNAL(authenticationRequired(
            QNetworkReply*,QAuthenticator*)),
        this,SLOT(onAuthenticationRequired(
            QNetworkReply*,QAuthenticator*)));
    //认证成功后,响应数据到来,发送信号readyRead
    connect(reply,SIGNAL(readyRead()),
            this,SLOT(onReadyRead()));
    //响应数据接收结束,发送信号finished
    connect(reply,SIGNAL(finished()),
            this,SLOT(onFinished()));
}
//验证登录的槽函数
void MainWindow::onAuthenticationRequired(
    QNetworkReply*,QAuthenticator* a)
{
    //qDebug("onAuthenticationRequired");
    //任务1:增加登录对话框
    //从登录界面获取用户名和密码再做认证
    a->setUser("tarenacode");
    a->setPassword("code_2013");
}
//接收响应数据的槽函数
void MainWindow::onReadyRead(void)
{
    //qDebug("onReadyRead");
    //读取响应数据并保存
    buf += reply->readAll();
    //记录当前Url
    currentUrl = reply->url();
}
//接收响应数据结束时执行的槽函数
void MainWindow::onFinished(void)
{
    //qDebug("onFinished");
    //显示收到的数据
    ui->textBrowser->setText(buf);
    //清空buf
    buf.clear();
    //销毁reply对象
    reply->deleteLater();
}
//处理目录链接的槽函数,参数当前点击的Url
void MainWindow::onAnchorClicked(
        const QUrl &url)
{
    //http://code.tarena.com.cn/
    //qDebug() << "当前Url:" << currentUrl;
    //CSDCode/
   // qDebug() << "点击Url:" << url;

    //点击新链接完整Url
    QUrl newUrl;

    //如果点击链接不是"../",要进入的新的链接:
    //newUrl=当前Url+点击Url
    if(url.toString() != "../"){
        newUrl = currentUrl.toString() +
                url.toString();
    }
    else{//处理"../"
        //如果在首界面,则什么也不做
        if(currentUrl.toString() ==
                "http://code.tarena.com.cn/"){
            qDebug() << currentUrl;
            return;
        }
        //如果不在首界面,则去掉最后一级路径
        //eg:http://code.tarena.com.cn/CSDCode/
        //newUrl:http://code.tarena.com.cn/
        //查找倒数第二次出现"/"索引
        int pos = currentUrl.toString(
                 ).lastIndexOf("/",-2);
        //截断到倒数第二次出现"/"的位置
        newUrl = currentUrl.toString(
                 ).mid(0,pos+1);
    }

    //判断newUrl是否对应文件链接,是则执行下载文件操作
    if(url.toString().lastIndexOf("/")==-1){
        //qDebug() << "下载文件:" << newUrl;
        //任务二:创建子线程,将文件下载过程放到子线程中
        downloadFile(newUrl);
        return;
    }

    //设置请求为新的Url
    request.setUrl(newUrl);
    //发送新的请求
    sendRequest();
}

//发送下载文件的请求
void MainWindow::downloadFile(
        const QUrl& fileUrl)
{
    //根据文件Url获取要下载的文件名
    QFileInfo fileInfo = fileUrl.path();
    QString filename = fileInfo.fileName();

    //在本地创建同名的文件
    file = new QFile(filename,this);
    file->open(QIODevice::WriteOnly);

    //向服务器发送获取文件内容的请求
    request.setUrl(fileUrl);
    reply = manager->get(request);

    //接收到响应数据(文件内容),发送信号readyRead
    connect(reply,SIGNAL(readyRead()),
            this,SLOT(receiveFile()));
    //伴随响应数据接收,发送表示下载进度信号
    //downloadProgress参数:已收到字节数/总字节数
    connect(reply,SIGNAL(
        downloadProgress(qint64,qint64)),
        this,SLOT(
        onDownloadProgress(qint64,qint64)));
    //接收响应数据完成(文件下载完成),发送信号finished
    connect(reply,SIGNAL(finished()),
        this,SLOT(receiveFileFinish()));
}
//接收文件内容的槽函数
void MainWindow::receiveFile()
{
    //接收文件内容并写入本地的同名文件
    file->write(reply->readAll());
}
//表示文件下载进度的槽函数
void MainWindow::onDownloadProgress(
        qint64 bytesReceive,qint64 bytesTotal)
{
    //计算百分比
    qint64 progress =
            bytesReceive*100/bytesTotal;
    //打印下载进度
    qDebug() << file->fileName() <<
            ":" << progress << "%...";
}
//文件下载完成执行的槽函数
void MainWindow::receiveFileFinish()
{
    qDebug() << file->fileName() <<
                ":文件下载完成!";
    file->flush();//刷新文件流
    file->close();//关闭文件
    reply->deleteLater();
}




