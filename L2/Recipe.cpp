#include <iostream>
#include <fstream>
#include <string>
#include "Recipe.h"

using namespace std;

Recipe::Recipe()
{
    name = "Unknown";
    ingredientCount = 0;
    ingredients = nullptr;
}

Recipe::~Recipe()
{
    delete[] ingredients;
}

void Recipe::setName(string value)
{
    name = value;
}

void Recipe::setIngredientCount(int value)
{
    ingredientCount = value;

    delete[] ingredients;
    ingredients = new Ingredient[ingredientCount];
}

string Recipe::getName()
{
    return name;
}

int Recipe::getIngredientCount()
{
    return ingredientCount;
}

double Recipe::calculateCost()
{
    double total = 0;

    for (int i = 0; i < ingredientCount; i++)
    {
        total = total +
            ingredients[i].getAmount() * ingredients[i].getPrice();
    }

    return total;
}

void Recipe::show()
{
    cout << "Recipe: " << name << endl;
    cout << "Ingredients:" << endl;

    for (int i = 0; i < ingredientCount; i++)
    {
        cout << endl;
        ingredients[i].show();
    }

    cout << "Total cost: " << calculateCost() << endl;
}

void Recipe::setIngredient(int index, Ingredient ingredient)
{
    ingredients[index] = ingredient;
}

void Recipe::saveToFile(string fileName)
{
    ofstream file(fileName);

    if (!file)
    {
        cout << "Cannot open file." << endl;
        return;
    }

    file << name << endl;
    file << ingredientCount << endl;

    for (int i = 0; i < ingredientCount; i++)
    {
        file << ingredients[i].getName() << endl;

        file << ingredients[i].getAmount() << " "
            << ingredients[i].getPrice() << endl;
    }

    file.close();

    cout << "Recipe saved to file." << endl;
}

void Recipe::findInFile(string fileName, string searchName)
{
    ifstream file(fileName);

    if (!file)
    {
        cout << "Cannot open file." << endl;
        return;
    }

    string recipeName;
    int count;

    while (getline(file, recipeName))
    {
        file >> count;
        file.ignore();

        if (recipeName == searchName)
        {
            cout << "Recipe found: " << recipeName << endl;

            for (int i = 0; i < count; i++)
            {
                string ingredientName;
                double amount;
                double price;

                getline(file, ingredientName);

                file >> amount >> price;
                file.ignore();

                cout << "Name: " << ingredientName << endl;
                cout << "Amount: " << amount << endl;
                cout << "Price: " << price << endl;
            }

            file.close();
            return;
        }

    }

    cout << "Recipe not found." << endl;

    file.close();
}