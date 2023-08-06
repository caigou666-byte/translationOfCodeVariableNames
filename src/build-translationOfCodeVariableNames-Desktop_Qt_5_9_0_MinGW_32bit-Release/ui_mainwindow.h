/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *translation_mode;
    QComboBox *named_type;
    QPushButton *TranslationButton;
    QCheckBox *windowTop;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QPlainTextEdit *LeftInputBox;
    QHBoxLayout *horizontalLayout;
    QPushButton *LeftClearContent;
    QPushButton *PasteLeft;
    QPushButton *LeftCopy;
    QVBoxLayout *verticalLayout_2;
    QPlainTextEdit *RightInputBox;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *RightClearContent;
    QPushButton *PasteRight;
    QPushButton *RightCopy;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(956, 562);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        MainWindow->setFont(font);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_3 = new QVBoxLayout(centralWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        translation_mode = new QComboBox(centralWidget);
        translation_mode->setObjectName(QStringLiteral("translation_mode"));
        QFont font1;
        font1.setPointSize(14);
        translation_mode->setFont(font1);

        horizontalLayout_3->addWidget(translation_mode);

        named_type = new QComboBox(centralWidget);
        named_type->setObjectName(QStringLiteral("named_type"));
        named_type->setFont(font1);

        horizontalLayout_3->addWidget(named_type);

        TranslationButton = new QPushButton(centralWidget);
        TranslationButton->setObjectName(QStringLiteral("TranslationButton"));
        TranslationButton->setFont(font);
        TranslationButton->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_3->addWidget(TranslationButton);


        verticalLayout_3->addLayout(horizontalLayout_3);

        windowTop = new QCheckBox(centralWidget);
        windowTop->setObjectName(QStringLiteral("windowTop"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(14);
        windowTop->setFont(font2);
        windowTop->setStyleSheet(QStringLiteral(""));
        windowTop->setIconSize(QSize(64, 64));

        verticalLayout_3->addWidget(windowTop);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        LeftInputBox = new QPlainTextEdit(centralWidget);
        LeftInputBox->setObjectName(QStringLiteral("LeftInputBox"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(16);
        LeftInputBox->setFont(font3);

        verticalLayout->addWidget(LeftInputBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        LeftClearContent = new QPushButton(centralWidget);
        LeftClearContent->setObjectName(QStringLiteral("LeftClearContent"));
        LeftClearContent->setFont(font);

        horizontalLayout->addWidget(LeftClearContent);

        PasteLeft = new QPushButton(centralWidget);
        PasteLeft->setObjectName(QStringLiteral("PasteLeft"));
        PasteLeft->setFont(font);

        horizontalLayout->addWidget(PasteLeft);

        LeftCopy = new QPushButton(centralWidget);
        LeftCopy->setObjectName(QStringLiteral("LeftCopy"));
        LeftCopy->setFont(font);

        horizontalLayout->addWidget(LeftCopy);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_4->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        RightInputBox = new QPlainTextEdit(centralWidget);
        RightInputBox->setObjectName(QStringLiteral("RightInputBox"));
        RightInputBox->setFont(font3);

        verticalLayout_2->addWidget(RightInputBox);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        RightClearContent = new QPushButton(centralWidget);
        RightClearContent->setObjectName(QStringLiteral("RightClearContent"));
        RightClearContent->setFont(font);

        horizontalLayout_2->addWidget(RightClearContent);

        PasteRight = new QPushButton(centralWidget);
        PasteRight->setObjectName(QStringLiteral("PasteRight"));
        PasteRight->setFont(font);

        horizontalLayout_2->addWidget(PasteRight);

        RightCopy = new QPushButton(centralWidget);
        RightCopy->setObjectName(QStringLiteral("RightCopy"));
        RightCopy->setFont(font);

        horizontalLayout_2->addWidget(RightCopy);


        verticalLayout_2->addLayout(horizontalLayout_2);


        horizontalLayout_4->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout_4);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        translation_mode->clear();
        translation_mode->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\344\270\255\346\226\207\347\277\273\350\257\221\344\270\272\350\213\261\346\226\207", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\350\213\261\346\226\207\347\277\273\350\257\221\344\270\272\344\270\255\346\226\207", Q_NULLPTR)
        );
        named_type->clear();
        named_type->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\345\260\217\351\251\274\345\263\260", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\244\247\351\251\274\345\263\260", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\344\270\213\345\210\222\347\272\277", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\270\270\351\207\217", Q_NULLPTR)
         << QApplication::translate("MainWindow", "CSS\347\261\273\345\220\215", Q_NULLPTR)
        );
        TranslationButton->setText(QApplication::translate("MainWindow", "\347\277\273\350\257\221", Q_NULLPTR));
        windowTop->setText(QApplication::translate("MainWindow", "\347\252\227\345\217\243\347\275\256\351\241\266", Q_NULLPTR));
        LeftClearContent->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272\345\206\205\345\256\271", Q_NULLPTR));
        PasteLeft->setText(QApplication::translate("MainWindow", "\347\262\230\350\264\264", Q_NULLPTR));
        LeftCopy->setText(QApplication::translate("MainWindow", "\345\244\215\345\210\266", Q_NULLPTR));
        RightClearContent->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272\345\206\205\345\256\271", Q_NULLPTR));
        PasteRight->setText(QApplication::translate("MainWindow", "\347\262\230\350\264\264", Q_NULLPTR));
        RightCopy->setText(QApplication::translate("MainWindow", "\345\244\215\345\210\266", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
