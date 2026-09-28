#pragma once

class Ingredient
{
private:
    char* name;
    double amount;
    double price;

public:
    Ingredient();
    Ingredient(const Ingredient& other);
    ~Ingredient();

    Ingredient& operator=(const Ingredient& other);

    void setName(char* value);
    void setAmount(double value);
    void setPrice(double value);

    char* getName();
    double getAmount();
    double getPrice();

    void show();
};