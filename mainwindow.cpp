#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include<QClipboard>

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QByteArray>
#include <QDebug>
#include <QUrlQuery>
#include<iostream>
using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//ui->windowTop->che
connect(ui->windowTop, &QCheckBox::stateChanged, this, &MainWindow::onCheckBoxStateChanged);
connect(ui->LeftClearContent, &QPushButton::clicked, this, &MainWindow::LeftClearContent);
connect(ui->PasteLeft, &QPushButton::clicked, this, &MainWindow::PasteLeft);
connect(ui->LeftCopy, &QPushButton::clicked, this, &MainWindow::LeftCopy);

connect(ui->RightClearContent, &QPushButton::clicked, this, &MainWindow::RightClearContent);
connect(ui->PasteRight, &QPushButton::clicked, this, &MainWindow::PasteRight);
connect(ui->RightCopy, &QPushButton::clicked, this, &MainWindow::RightCopy);

connect(ui->TranslationButton, &QPushButton::clicked, this, &MainWindow::TranslationButton);
}

MainWindow::~MainWindow()
{
    delete ui;
}
// 槽函数，用于处理复选框选中状态的变化
void MainWindow::onCheckBoxStateChanged(int state)
{
    if (state == Qt::Checked)
    {
        setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);
        this->show();
//        QMessageBox::information(this, "提示", "复选框选中了！");
    }
    else if (state == Qt::Unchecked)
    {
        setWindowFlags(windowFlags() & ~Qt::WindowStaysOnTopHint);
        this->show();
//        QMessageBox::information(this, "提示", "复选框取消选中了！");
    }
}
void MainWindow::LeftClearContent(){
    this->ui->LeftInputBox->setPlainText("");
}
void MainWindow::PasteLeft(){
    // 获取剪贴板
        QClipboard *clipboard = QApplication::clipboard();

        // 粘贴剪贴板中的文本到输入框
        this->ui->LeftInputBox->setPlainText(clipboard->text());
}
void MainWindow::LeftCopy(){
    // 获取剪贴板
        QClipboard *clipboard = QApplication::clipboard();
clipboard->setText(this->ui->LeftInputBox->toPlainText());
}


void MainWindow::RightClearContent(){
    this->ui->RightInputBox->setPlainText("");
}
void MainWindow::PasteRight(){
    // 获取剪贴板
        QClipboard *clipboard = QApplication::clipboard();

        // 粘贴剪贴板中的文本到输入框
        this->ui->RightInputBox->setPlainText(clipboard->text());
}
void MainWindow::RightCopy(){
    // 获取剪贴板
        QClipboard *clipboard = QApplication::clipboard();
clipboard->setText(this->ui->RightInputBox->toPlainText());
}
void MainWindow::TranslationButton(){
cout<<1<<endl;
// 创建网络访问管理器
   QNetworkAccessManager manager;

   // 创建请求对象
   QNetworkRequest request;
   request.setUrl(QUrl("https://fanyi.phpstudyhelper.com/TranslateWord"));

   // 设置请求头
   request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

   // 创建请求参数
   QUrlQuery params;
   params.addQueryItem("word", "%E7%BF%BB%E8%AF%91%E6%8C%89%E9%92%AE");
   params.addQueryItem("named_type", "2");
   params.addQueryItem("translation_mode", "1");

   // 将请求参数编码为请求体
   QByteArray requestBody = params.toString(QUrl::FullyEncoded).toUtf8();

   // 发送POST请求
   QNetworkReply *reply = manager.post(request, requestBody);

   // 连接请求完成信号
   QObject::connect(reply, &QNetworkReply::finished, [&]() {
       // 读取响应数据
       QByteArray responseData = reply->readAll();

       // 打印响应结果
       qDebug() << "Response: " << responseData;

       // 释放资源
       reply->deleteLater();

   });
}
