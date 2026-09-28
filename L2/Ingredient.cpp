#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "Ingredient.h"

using namespace std;

Ingredient::Ingredient()
{
    name = new char[8];
    strcpy(name, "Unknown");

    amount = 0;
    price = 0;
}

Ingredient::Ingredient(const Ingredient& other)
{
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);

    amount = other.amount;
    price = other.price;
}

Ingredient::~Ingredient()
{
    delete[] name;
}

Ingredient& Ingredient::operator=(const Ingredient& other)
{
    if (this != &other)
    {
        setName(other.name);
        amount = other.amount;
        price = other.price;
    }

    return *this;
}

void Ingredient::setName(char* value)
{
    delete[] name;

    name = new char[strlen(value) + 1];
    strcpy(name, value);
}

void Ingredient::setAmount(double value)
{
    amount = value;
}

void Ingredient::setPrice(double value)
{
    price = value;
}

char* Ingredient::getName()
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