#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
private slots:
    void onCheckBoxStateChanged(int state);
    void LeftClearContent();
    void PasteLeft();
    void LeftCopy();
    void RightClearContent();
    void PasteRight();
    void RightCopy();
    void TranslationButton();
};

#endif // MAINWINDOW_H
