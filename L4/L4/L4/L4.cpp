#define _USE_MATH_DEFINES
#include <iostream>
#include <fstream>
#include <cmath>
#include <sstream>
#include <string>
#include <stdexcept>

using namespace std;

double vvestyDodatneChyslo(const char* povidomlennia) {
    double x;
    string ryadok;

    while (true) {
        cout << povidomlennia;
        getline(cin, ryadok);

        stringstream potik(ryadok);
        char sim;

        if (potik >> x &&
            !(potik >> sim) &&
            isfinite(x) && x > 0) {
            return x;
        }

        cout << "Помилка! Введiть правильне додатне число."
            << endl;
    }
}

class Kolo {
protected:
    double r;

public:
    Kolo(double radius) {
        r = radius;
    }

    double ploshchaKola() {
        return M_PI * r * r;
    }

    double dovzhynaKola() {
        return 2 * M_PI * r;
    }

    void vyvidKola(ostream& out) {
        out << "Коло:" << endl;
        out << "Радiус: " << r << endl;
        out << "Площа: " << ploshchaKola() << endl;
        out << "Довжина кола: " << dovzhynaKola() << endl;
    }
};

class Romb {
protected:
    double d1, d2;

public:
    Romb(double diagonal1, double diagonal2) {
        d1 = diagonal1;
        d2 = diagonal2;
    }

    double ploshchaRomba() {
        return d1 * d2 / 2;
    }

    double radiusVpysanogoKola() {
        return d1 * d2 /
            (2 * sqrt(d1 * d1 + d2 * d2));
    }

    void vyvidRomba(ostream& out) {
        out << "Ромб:" << endl;
        out << "Перша dіагональ: " << d1 << endl;
        out << "Друга dіагональ: " << d2 << endl;
        out << "Площа: " << ploshchaRomba() << endl;
    }
};

class KoloVRombi : public Kolo, public Romb {
public:
    KoloVRombi(double radius, double diagonal1, double diagonal2)
        : Kolo(radius), Romb(diagonal1, diagonal2) {

        double rVpisane = radiusVpysanogoKola();

        if (abs(r - rVpisane) > 0.00001) {
            throw invalid_argument(
                "Коло не вписане у ромб! Радiус кола не вiдповiдає "
                "радiусу вписаного кола."
            );
        }
    }

    void vyvidInformatsii(ostream& out) {
        out << "Коло, вписане у ромб" << endl;
        out << "------------------------" << endl;

        vyvidKola(out);

        out << "------------------------" << endl;

        vyvidRomba(out);

        out << "------------------------" << endl;
        out << "Коло вписане у ромб." << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ukr");

    double r, d1, d2;

    r = vvestyDodatneChyslo("Введiть радiус кола: ");

    d1 = vvestyDodatneChyslo(
        "Введiть першу дiагональ ромба: ");

    d2 = vvestyDodatneChyslo(
        "Введiть другу дiагональ ромба: ");

    try {
        KoloVRombi figura(r, d1, d2);

        cout << endl;
        figura.vyvidInformatsii(cout);

        ofstream file("figury.txt");

        if (!file.is_open()) {
            cout << "Не вдалося вiдкрити файл." << endl;
            return 1;
        }

        figura.vyvidInformatsii(file);
        file.close();

        cout << endl;
        cout << "Iнформацiю записано у файл figury.txt" << endl;
    }
    catch (const invalid_argument& e) {
        cout << endl;
        cout << "Помилка: " << e.what() << endl;
        return 1;
    }

    return 0;
}