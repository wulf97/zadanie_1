#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "implement.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    bool fl = false;

private slots:
    void buttPressed();  //нажатие на кнопку
};

#endif // MAINWINDOW_H
