#include "mainwindow.h"
#include <QApplication>
#include <QFile>
#include<QTextStream>
#include<iostream>

using namespace std;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    // 读取QSS文件
    QFile qssFile(":/qss/style.qss");
    if (qssFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        cout << "load qss success" << endl;
        QTextStream stream(&qssFile);
        QString qss = stream.readAll();
        qssFile.close();

        // 应用样式表
        a.setStyleSheet(qss);
    }

    MainWindow w;
    w.show();

    return a.exec();
}
