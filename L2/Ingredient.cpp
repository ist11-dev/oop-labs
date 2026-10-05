#include <iostream>
#include <string>
#include "Ingredient.h"

using namespace std;

Ingredient::Ingredient()
{
    name = "Unknown";

    amount = 0;
    price = 0;
}

Ingredient::Ingredient(const Ingredient& other)
{
    name = other.name;
    amount = other.amount;
    price = other.price;
}

Ingredient::~Ingredient()
{
}

Ingredient& Ingredient::operator=(const Ingredient& other)
{
    if (this != &other)
    {
        name = other.name;
        amount = other.amount;
        price = other.price;
    }

    return *this;
}

void Ingredient::setName(string value)
{
    name = value;
}

void Ingredient::setAmount(double value)
{
    amount = value;
}

void Ingredient::setPrice(double value)
{
    price = value;
}

string Ingredient::getName()
{
    return name;
}

double Ingredient::getAmount()
{
    return amount;
}

double Ingredient::getPrice()
{
    return price;
}

void Ingredient::show()
{
    cout << "Name: " << name << endl;
    cout << "Amount: " << amount << endl;
    cout << "Price: " << price << endl;
}
