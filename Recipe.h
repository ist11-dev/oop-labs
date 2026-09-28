#pragma once

#include "Ingredient.h"

class Recipe
{
private:
    char* name;
    Ingredient* ingredients;
    int ingredientCount;

public:
    Recipe();
    ~Recipe();

    void setName(char* value);
    void setIngredientCount(int value);

    char* getName();
    int getIngredientCount();

    void show();

    double calculateCost();
    void setIngredient(int index, Ingredient ingredient);
    void saveToFile(char* fileName);
    void findInFile(char* fileName, char* searchName);
};
