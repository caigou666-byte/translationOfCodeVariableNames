#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

private:
    Ui::MainWindow *ui;
    int named_type = 1;
    int translation_mode = 1;
private
    slots:
            void onCheckBoxStateChanged(int
    state);

    void LeftClearContent();

    void PasteLeft();

    void LeftCopy();

    void RightClearContent();

    void PasteRight();

    void RightCopy();

    void TranslationButton();

    void translation_mode_CurrentIndexChanged(int index);

    void named_type_CurrentIndexChanged(int index);
};

#endif // MAINWINDOW_H
