#include <iostream>
using namespace std;

template <typename T>
class Calculator {
public:
    virtual T add(T a, T b) = 0;
    virtual T subtract(T a, T b) = 0;
    virtual T multiply(T a, T b) = 0;
    virtual T divide(T a, T b) = 0;

    virtual ~Calculator() {}
};

class IntegerCalculator : public Calculator<int> {
public:
    int add(int a, int b) override {
        return a + b;
    }

    int subtract(int a, int b) override {
        return a - b;
    }

    int multiply(int a, int b) override {
        return a * b;
    }

    int divide(int a, int b) override {
        return a / b;
    }
};

class DecimalCalculator : public Calculator<double> {
public:
    double add(double a, double b) override {
        return a + b;
    }

    double subtract(double a, double b) override {
        return a - b;
    }

    double multiply(double a, double b) override {
        return a * b;
    }

    double divide(double a, double b) override {
        return a / b;
    }
};

int main() {
    setlocale(LC_ALL, "ukr");

    IntegerCalculator intCalc;
    DecimalCalculator decCalc;

    Calculator<int>* intPtr = &intCalc;
    Calculator<double>* decPtr = &decCalc;

    double a, b;
    int choice, type;

    cout << "Оберiть тип чисел:\n";
    cout << "1 - Цiлi числа\n";
    cout << "2 - Десятковi числа\n";
    cout << "Ваш вибiр: ";
    cin >> type;

    if (type == 1) {
        int x, y;

        cout << "Введiть перше число: ";
        cin >> x;

        cout << "Введiть друге число: ";
        cin >> y;

        cout << "\nОберiть арифметичну операцiю:\n";
        cout << "1 - Додавання\n";
        cout << "2 - Вiднiмання\n";
        cout << "3 - Множення\n";
        cout << "4 - Дiлення\n";
        cout << "Ваш вибiр: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Результат: " << intPtr->add(x, y);
            break;

        case 2:
            cout << "Результат: " << intPtr->subtract(x, y);
            break;

        case 3:
            cout << "Результат: " << intPtr->multiply(x, y);
            break;

        case 4:
            if (y == 0) {
                cout << "На нуль дiлити не можна!";
            }
            else {
                cout << "Результат: " << intPtr->divide(x, y);
            }
            break;

        default:
            cout << "Неправильний вибiр операцiї!";
        }
    }
    else if (type == 2) {
        double x, y;

        cout << "Введiть перше число: ";
        cin >> x;

        cout << "Введiть друге число: ";
        cin >> y;

        cout << "\nОберiть арифметичну операцiю:\n";
        cout << "1 - Додавання\n";
        cout << "2 - Вiднiмання\n";
        cout << "3 - Множення\n";
        cout << "4 - Дiлення\n";
        cout << "Ваш вибiр: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Результат: " << decPtr->add(x, y);
            break;

        case 2:
            cout << "Результат: " << decPtr->subtract(x, y);
            break;

        case 3:
            cout << "Результат: " << decPtr->multiply(x, y);
            break;

        case 4:
            if (y == 0) {
                cout << "На нуль дiлити не можна!";
            }
            else {
                cout << "Результат: " << decPtr->divide(x, y);
            }
            break;

        default:
            cout << "Неправильний вибiр операцiї!";
        }
    }
    else {
        cout << "Неправильний вибiр типу чисел!";
    }

    return 0;
}