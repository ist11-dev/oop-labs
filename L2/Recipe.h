#pragma once

#include <string>
#include "Ingredient.h"

using namespace std;

class Recipe
{
private:
    string name;
    Ingredient* ingredients;
    int ingredientCount;

public:
    Recipe();
    ~Recipe();

    void setName(string value);
    void setIngredientCount(int value);

    string getName();
    int getIngredientCount();

    void show();

    double calculateCost();
    void setIngredient(int index, Ingredient ingredient);
    void saveToFile(string fileName);
    void findInFile(string fileName, string searchName);
};