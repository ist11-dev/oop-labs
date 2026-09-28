#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "Recipe.h"
#include <fstream>
using namespace std;

Recipe::Recipe()
{
    name = new char[8];
    strcpy(name, "Unknown");

    ingredientCount = 0;
    ingredients = nullptr;
}

Recipe::~Recipe()
{
    delete[] name;
    delete[] ingredients;
}

void Recipe::setName(char* value)
{
    delete[] name;

    name = new char[strlen(value) + 1];
    strcpy(name, value);
}

void Recipe::setIngredientCount(int value)
{
    ingredientCount = value;

    delete[] ingredients;
    ingredients = new Ingredient[ingredientCount];
}

char* Recipe::getName()
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

void Recipe::saveToFile(char* fileName)
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

void Recipe::findInFile(char* fileName, char* searchName)
{
    ifstream file(fileName);

    if (!file)
    {
        cout << "Cannot open file." << endl;
        return;
    }

    char recipeName[100];
    int count;

    while (file.getline(recipeName, 100))
    {
        file >> count;
        file.ignore();

        if (strcmp(recipeName, searchName) == 0)
        {
            cout << "Recipe found: " << recipeName << endl;

            for (int i = 0; i < count; i++)
            {
                char ingredientName[100];
                double amount;
                double price;

                file.getline(ingredientName, 100);
                file >> amount >> price;
                file.ignore();

                cout << "Name: " << ingredientName << endl;
                cout << "Amount: " << amount << endl;
                cout << "Price: " << price << endl;
            }

            file.close();
            return;
        }

        // Пропускаємо інгредієнти цього рецепту
        for (int i = 0; i < count; i++)
        {
            file.ignore(100, '\n');
            file.ignore(100, '\n');
        }
    }

    cout << "Recipe not found." << endl;

    file.close();
}