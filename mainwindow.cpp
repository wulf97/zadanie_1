#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    QPushButton *numButtons[10];
    QPushButton *ansButton;
    QPushButton *plusButton;
    QPushButton *minButton;
    QPushButton *mulButton;
    QPushButton *divButton;
    QPushButton *modButton;
    QPushButton *delButton;
    QPushButton *cButton;
    QPushButton *dotButton;

    ui->setupUi(this);
    ui->display->setText("0");
    for (int i = 0; i < 10; ++i) {
        QString buttonName = "button" + QString::number(i);
        /* Добавление кнопки в массив по их имени */
        numButtons[i] = MainWindow::findChild<QPushButton*>(buttonName);
        /* Обработка нажатия одной из кнопок */
        connect(numButtons[i], SIGNAL(released()), this, SLOT(buttPressed()));
    }

    ansButton = MainWindow::findChild<QPushButton*>("buttonAns");
    plusButton = MainWindow::findChild<QPushButton*>("buttonPlus");
    minButton = MainWindow::findChild<QPushButton*>("buttonMinus");
    mulButton = MainWindow::findChild<QPushButton*>("buttonMul");
    divButton = MainWindow::findChild<QPushButton*>("buttonDiv");
    modButton = MainWindow::findChild<QPushButton*>("buttonPercent");
    delButton = MainWindow::findChild<QPushButton*>("buttonRemoveOne");
    cButton = MainWindow::findChild<QPushButton*>("buttonC");
    dotButton = MainWindow::findChild<QPushButton*>("buttonDot");

    connect(ansButton, SIGNAL(released()), this, SLOT(buttPressed()));
    connect(plusButton, SIGNAL(released()), this, SLOT(buttPressed()));
    connect(minButton, SIGNAL(released()), this, SLOT(buttPressed()));
    connect(mulButton, SIGNAL(released()), this, SLOT(buttPressed()));
    connect(divButton, SIGNAL(released()), this, SLOT(buttPressed()));
    connect(modButton, SIGNAL(released()), this, SLOT(buttPressed()));
    connect(delButton, SIGNAL(released()), this, SLOT(buttPressed()));
    connect(cButton, SIGNAL(released()), this, SLOT(buttPressed()));
    connect(dotButton, SIGNAL(released()), this, SLOT(buttPressed()));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::buttPressed(void) {
    QPushButton *button;
    QString newVal, buttonVal, screenVal;
    Implement res;

    /* Возвращает указатель на нажатую кнопку */
    button = (QPushButton*)sender();
    buttonVal = button->text();
    screenVal = ui->display->text();

    if (buttonVal != "C" &&
        buttonVal != "<<" &&
        buttonVal != "=") {

        if (buttonVal == "+" ||
            buttonVal == "-" ||
            buttonVal == "*" ||
            buttonVal == "/" ||
            buttonVal == "%") {

            if (this->fl == true)
                newVal = screenVal.remove(screenVal.size() - 1, screenVal.size()) + buttonVal;
            else
                newVal = screenVal + buttonVal;

            this->fl = true;
        } else {
            this->fl = false;

            if (screenVal == "0")
                newVal = buttonVal;
            else
                newVal = screenVal + buttonVal;
        }

    } else {
        if (buttonVal == "=")
            newVal = QString::number(res.calc(screenVal));
        if (buttonVal == "<<") {
            if (screenVal.length() >= 1)
                if (screenVal.length() == 1)
                    newVal = "0";
                else
                    newVal = screenVal.remove(screenVal.size() - 1, screenVal.size());

            if (newVal[screenVal.size() - 1] == "+" ||
                newVal[screenVal.size() - 1] == "-" ||
                newVal[screenVal.size() - 1] == "*" ||
                newVal[screenVal.size() - 1] == "/" ||
                newVal[screenVal.size() - 1] == "%")
                fl = true;
        }

        if (buttonVal == "C")
            newVal = "0";
    }

    ui->display->setText(newVal);
}
