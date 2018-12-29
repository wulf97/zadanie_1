#include "implement.h"

Implement::Implement() {

}

float Implement::calc(QString &str) {
    std::stack<float> nu; // Стек для операндов
    std::stack<Operator> op; // Стек для операторов
    std::vector<float> num; // Массив чисел в выражении
    std::vector<Operator> operators; // Массив операторов в выражении
    QString numStr = "";
    char ch;
    float res;

    qDebug() << "len = " << str.length();
    qDebug() << str << endl;
    numStr = "";
    for (int i = 0; i <= str.length(); i++) {
        if (str[i] == "+" ||
            str[i] == "-" ||
            str[i] == "*" ||
            str[i] == "/" ||
            str[i] == "%" ||
            i == str.length()) {
            num.push_back(numStr.toFloat());
            numStr = "";
            if (i != str.length()) {
                Operator _op;
                _op.val = str.toLocal8Bit().at(i);
                if (_op.val == '+' ||
                    _op.val == '-')
                    _op.pri = 1;
                if (_op.val == '*' ||
                    _op.val == '/' ||
                    _op.val == '%')
                    _op.pri = 2;
                operators.push_back(_op);
            }
        } else {
            numStr += str[i];
        }
    }

    if (num.size() == 1)
        res = num[0];

    if (operators.size() >= 1) {
        nu.push(num[0]);
        for (int i = 0; i < operators.size(); i++) {
            op.push(operators[i]); // Запишем оператор в стек
            nu.push(num[i + 1]); // Запишем операнд в стек
            if (op.top().pri >= operators[i + 1].pri) {
                qDebug() << "*" << endl;
                qDebug() << "i=" << i <<endl;
                this->doOperation(op, nu);
            }
        }

        while (op.size() >= 1)
            this->doOperation(op, nu);

        res = nu.top();
    }

    while (!nu.empty())
        nu.pop();

    while (!op.empty())
        op.pop();

    num.clear();
    operators.clear();

    return res;
}


void Implement::doOperation(std::stack<Operator> &op, std::stack<float> &nu) {
    float num1, num2, res;
    char ch;

    num2 = nu.top();
    nu.pop();
    num1 = nu.top();
    nu.pop();
    ch = op.top().val;
    op.pop();

    switch (ch) {
        case '+':
            res = num1 + num2;
        break;
        case '-':
            res = num1 - num2;
        break;
        case '*':
            res = num1 * num2;
        break;
        case '/':
            res = num1 / num2;
        break;
        case '%':
            res = fmod(num1, num2);
        break;
    }

    qDebug() << "res = " <<  res << endl;
    nu.push(res);
}
