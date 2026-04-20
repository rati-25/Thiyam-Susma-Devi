#include "classes.h"
#include <bits/stdc++.h>
using namespace std;

//function for dish class
double Dish::getDishPrice()
{
    return this->dishPrice;
}
string Dish::getDishName()
{
    return this->dishName;
}
string Dish::getDishType()
{
    return this->dishType;
}
void Dish::setDishPrice(double P)
{
    this->dishPrice = P;
}

//functions for drink class
string Drink::getDrinkName()
{
    return this->drinkName;
}
double Drink::getDrinkPrice()
{
    return this->drinkPrice;
}
void Drink::setDrinkPrice(double P)
{
    this->drinkPrice = P;
}


//functions for cuisine class
void Cuisine::addDish(Dish D)
{
    this->menu.push_back(D);
    return;
}
void Cuisine::removeDish(Dish D)
{
    vector<Dish>::iterator add = find(menu.begin(), menu.end(), D);
    if (add != menu.end())
    {
        menu.erase(add);
    }
    else
    {
        cout << "Dish ain't in the menu\n";
    }
    return;
}
void Cuisine::showMenu()
{
    cout << "-------------------MENU-------------------\n";
    cout << "DISH                               Price\n";
    for (auto it : this->menu)
    {
        cout << it.getDishName() << "\t\t\t\t" << it.getDishPrice() << endl;
    }
    cout << endl;
}