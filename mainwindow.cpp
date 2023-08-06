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
#include <QJsonDocument>
#include <QJsonObject>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow) {
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

    // 连接currentIndexChanged信号到槽函数
    connect(ui->named_type, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &MainWindow::named_type_CurrentIndexChanged);
    connect(ui->translation_mode, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &MainWindow::translation_mode_CurrentIndexChanged);

}

MainWindow::~MainWindow() {
    delete ui;
}

// 槽函数，用于处理复选框选中状态的变化
void MainWindow::onCheckBoxStateChanged(int state) {
    if (state == Qt::Checked) {
        setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);
        this->show();
//        QMessageBox::information(this, "提示", "复选框选中了！");
    } else if (state == Qt::Unchecked) {
        setWindowFlags(windowFlags() & ~Qt::WindowStaysOnTopHint);
        this->show();
//        QMessageBox::information(this, "提示", "复选框取消选中了！");
    }
}

void MainWindow::LeftClearContent() {
    this->ui->LeftInputBox->setPlainText("");
}

void MainWindow::PasteLeft() {
    // 获取剪贴板
    QClipboard *clipboard = QApplication::clipboard();

    // 粘贴剪贴板中的文本到输入框
    this->ui->LeftInputBox->setPlainText(clipboard->text());
}

void MainWindow::LeftCopy() {
    // 获取剪贴板
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(this->ui->LeftInputBox->toPlainText());
}


void MainWindow::RightClearContent() {
    this->ui->RightInputBox->setPlainText("");
}

void MainWindow::PasteRight() {
    // 获取剪贴板
    QClipboard *clipboard = QApplication::clipboard();

    // 粘贴剪贴板中的文本到输入框
    this->ui->RightInputBox->setPlainText(clipboard->text());
}

void MainWindow::RightCopy() {
    // 获取剪贴板
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(this->ui->RightInputBox->toPlainText());
}

void MainWindow::TranslationButton() {
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);

    connect(manager, &QNetworkAccessManager::finished, this, [this](QNetworkReply *reply) {
        if (reply->error()) {
            qDebug() << "ERROR: " << reply->errorString();
        } else {
            QByteArray byteArray = reply->readAll();
            QJsonDocument jsonDoc = QJsonDocument::fromJson(byteArray);
            if (!jsonDoc.isNull()) {// 检查JSON是否有效
                QJsonObject jsonObj = jsonDoc.object();// 将JSON转换为QJsonObject
                if (jsonObj.contains("data")) {// 检查data字段是否存在
                    QJsonValue dataValue = jsonObj.value("data");// 获取data字段的值
                    if (dataValue.isObject()) {// 检查data字段的值是否是对象类型
                        QJsonObject dataObj = dataValue.toObject();// 将data字段的值转换为QJsonObject
                        if (dataObj.contains("word")) {// 检查word字段是否存在
                            QJsonValue wordValue = dataObj.value("word");// 获取word字段的值
                            if (wordValue.isString()) { // 检查word字段的值是否是字符串类型
                                QString word = wordValue.toString();// 获取word字段的字符串值
                                qDebug() << "Word: " << word;// 输出word字段的值
                                this->ui->RightInputBox->setPlainText(word);
                            }
                        }
                    }
                }
            }
        }
        reply->deleteLater();
    });
    if (this->ui->LeftInputBox->toPlainText() == "") {
        qDebug() << "左输入框内容为空！";
        return;
    }
    QUrlQuery postData;
    postData.addQueryItem("word", ui->LeftInputBox->toPlainText());
    postData.addQueryItem("named_type", QString::number(this->named_type));
    postData.addQueryItem("translation_mode", QString::number(this->translation_mode));
    QNetworkRequest request(QUrl("https://fanyi.phpstudyhelper.com/TranslateWord"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    manager->post(request, postData.toString(QUrl::FullyEncoded).toUtf8());
}


void MainWindow::translation_mode_CurrentIndexChanged(int index) {
    this->translation_mode = index + 1;
}

void MainWindow::named_type_CurrentIndexChanged(int index) {
    this->named_type = index + 1;
}
