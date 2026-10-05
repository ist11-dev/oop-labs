#pragma once

#include <string>
using namespace std;

class Ingredient
{
private:
    string name;
    double amount;
    double price;

public:
    Ingredient();
    Ingredient(const Ingredient& other);
    ~Ingredient();

    Ingredient& operator=(const Ingredient& other);

    void setName(string value);
    void setAmount(double value);
    void setPrice(double value);

    string getName();
    double getAmount();
    double getPrice();

    void show();
};


