#include <iostream>
#include <string>

using namespace std;

class ElectricityAccount {
private:
    double pricePerKwh;
    string date;
    double paidAmount;

public:
    ElectricityAccount(double price = 0, string d = "01.01.2026", double paid = 0) {
        setPricePerKwh(price);
        setDate(d);
        setPaidAmount(paid);
    }

    void setPricePerKwh(double price) {
        if (price < 0)
            throw "Вартiсть кВт·год не може бути вiд'ємною!";

        pricePerKwh = price;
    }

    void setDate(const string& d) {
        if (d.empty())
            throw "Дата не може бути порожньою!";

        date = d;
    }

    void setPaidAmount(double paid) {
        if (paid < 0)
            throw "Сума не може бути вiд'ємною!";

        paidAmount = paid;
    }
    
    double getPricePerKwh() const {
        return pricePerKwh;
    }

    string getDate() const {
        return date;
    }

    double getPaidAmount() const {
        return paidAmount;
    }

    ElectricityAccount& operator++() {
        ++pricePerKwh;
        ++paidAmount;
        return *this;
    }

    ElectricityAccount& operator-=(double value) {
        if (value < 0)
            throw "Значення не може бути вiд'ємним!";

        if (pricePerKwh < value || paidAmount < value)
            throw "Зменшення призведе до вiд'ємного значення!";

        pricePerKwh -= value;
        paidAmount -= value;

        return *this;
    }

    void findByDate(const string& searchDate) const {
        if (date == searchDate) {
            cout << *this;
        }
    }

    void findByDate(int day, int month, int year) const {
        string searchDate =
            (day < 10 ? "0" : "") + to_string(day) + "." +
            (month < 10 ? "0" : "") + to_string(month) + "." +
            to_string(year);

        findByDate(searchDate);
    }

    friend ostream& operator<<(ostream& out, const ElectricityAccount& account) {
        out << "Дата: " << account.date << '\n';
        out << "Вартiсть 1 кВт·год: " << account.pricePerKwh << '\n';
        out << "Сплачена сума: " << account.paidAmount << '\n';

        return out;
    }

    friend istream& operator>>(istream& in, ElectricityAccount& account) {
        double price, paid;
        string d;

        cout << "Введiть вартiсть 1 кВт·год: ";
        if (!(in >> price))
            throw "Помилка введення вартостi!";

        cout << "Введiть дату (дд.мм.рррр): ";
        if (!(in >> d))
            throw "Помилка введення дати!";

        cout << "Введiть сплачену суму: ";
        if (!(in >> paid))
            throw "Помилка введення суми!";

        account.setPricePerKwh(price);
        account.setDate(d);
        account.setPaidAmount(paid);

        return in;
    }
};

int main() {
    setlocale(LC_ALL, "ukr");

    ElectricityAccount* accounts = nullptr;

    try {
        int n;

        cout << "Введiть кiлькiсть записiв (1-10): ";

        if (!(cin >> n) || n < 1 || n > 10)
            throw "Кiлькiсть записiв має бути від 1 до 10!";

        accounts = new ElectricityAccount[n];

        for (int i = 0; i < n; i++) {
            cout << "\nЗапис №" << i + 1 << '\n';
            cin >> accounts[i];
        }

        cout << "\n--- Розрахункова книга електроенергiї ---\n";

        for (int i = 0; i < n; i++) {
            cout << accounts[i] << '\n';
        }

        int choice;

        cout << "Виберiть дiю:\n";
        cout << "1 - Збiльшити показники на 1 (++).\n";
        cout << "2 - Зменшити показники (-=).\n";
        cout << "3 - Пошук за датою.\n";
        cout << "Ваш вибiр: ";

        if (!(cin >> choice))
            throw "Помилка введення дiї!";

        switch (choice) {
        case 1: {
            int index;

            cout << "Введiть номер запису (1-" << n << "): ";

            if (!(cin >> index) || index < 1 || index > n)
                throw "Неправильний номер запису!";

            ++accounts[index - 1];

            cout << "\nПiсля збiльшення:\n";
            cout << accounts[index - 1];
            break;
        }

        case 2: {
            int index;
            double value;

            cout << "Введiть номер запису (1-" << n << "): ";

            if (!(cin >> index) || index < 1 || index > n)
                throw "Неправильний номер запису!";

            cout << "Введiть величину зменшення: ";

            if (!(cin >> value))
                throw "Помилка введення величини!";

            accounts[index - 1] -= value;

            cout << "\nПiсля зменшення:\n";
            cout << accounts[index - 1];
            break;
        }

        case 3: {
            string searchDate;
            bool found = false;

            cout << "Введiть дату для пошуку (дд.мм.рррр): ";
            cin >> searchDate;

            cout << "\nРезультат пошуку:\n";

            for (int i = 0; i < n; i++) {
                if (accounts[i].getDate() == searchDate) {
                    cout << accounts[i] << '\n';
                    found = true;
                }
            }

            if (!found)
                cout << "Запис за такою датою не знайдено.\n";

            break;
        }

        default:
            cout << "Невiдома дiя.\n";
            break;
        }
    }
    catch (const char* message) {
        cout << "\nПомилка: " << message << '\n';
    }
    catch (...) {
        cout << "\nВиникла невiдома помилка.\n";
    }

    delete[] accounts;
    accounts = nullptr;

    return 0;
}