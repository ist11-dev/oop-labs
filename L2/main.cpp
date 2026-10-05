#include <iostream>
#include "Recipe.h"

using namespace std;

int main()
{
    Recipe recipe;

    char recipeName[] = "Pasta";
    recipe.setName(recipeName);

    recipe.setIngredientCount(3);

    Ingredient pasta;
    char pastaName[] = "Pasta";
    pasta.setName(pastaName);
    pasta.setAmount(0.3);
    pasta.setPrice(60);

    Ingredient cheese;
    char cheeseName[] = "Cheese";
    cheese.setName(cheeseName);
    cheese.setAmount(0.1);
    cheese.setPrice(200);

    Ingredient sauce;
    char sauceName[] = "Sauce";
    sauce.setName(sauceName);
    sauce.setAmount(0.2);
    sauce.setPrice(80);

    recipe.setIngredient(0, pasta);
    recipe.setIngredient(1, cheese);
    recipe.setIngredient(2, sauce);

    recipe.show();

    char fileName[] = "recipes.txt";
    recipe.saveToFile(fileName);

    cout << endl;

    char searchName[] = "Pasta";
    recipe.findInFile(fileName, searchName);

    return 0;
}