#include "mainwindow.h"
#include <QApplication>
#include <QFile>
#include<QTextStream>
#include<iostream>

using namespace std;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QFile qssFile(":/qss/style.qss");// 读取QSS文件
    if (qssFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        cout << "load qss success" << endl;
        QTextStream stream(&qssFile);
        QString qss = stream.readAll();
        qssFile.close();
        a.setStyleSheet(qss);// 应用样式表
    }
    MainWindow w;
    w.show();
    return a.exec();
}
