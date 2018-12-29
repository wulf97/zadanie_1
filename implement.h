#ifndef IMPLEMENT_H
#define IMPLEMENT_H

#include <stack>
#include <vector>
#include <math.h>

#include <QPushButton>
#include <QString>
#include <QDebug>

#include "ui_mainwindow.h"

/* Структура данных для храниня операции */
typedef struct {
    char val; // Значение оператора
    int pri; // Пиоритет оператора
} Operator;

class Implement {
public:
    Implement();

    float calc(QString&);
private:
    void doOperation(std::stack<Operator>&, std::stack<float>&);
};

#endif // IMPLEMENT_H
