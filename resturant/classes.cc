#include "classes.h"
#include <bits/stdc++.h>
using namespace std;

//function for dish class
Dish::Dish(string N = "not assigned", double P = 0.00):dishName(N), dishPrice(P){}
double Dish::getDishPrice()
{
    return this->dishPrice;
}
string Dish::getDishName()
{
    return this->dishName;
}
void Dish::setDishPrice(double P)
{
    this->dishPrice = P;
}
void Dish::showDishInfo()
{
    cout << "Name  :" << this->dishName << endl;
    cout << "Price :" << this->dishPrice << endl;
    cout << "Course:" << this->dishCourse << endl;
    cout << "Type  :" << this->dishType << endl;
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
Cuisine::Cuisine(): countDishes(0), countNonVegDishes(0), countVegDishes(0), firstVeg(menu.end()){}
void Cuisine::addDish(Dish D)
{
    if(D.getDishType() == "veg")
    {
        this->countVegDishes++;
        this->menu.push_back(D);
    }
    else
    {
        this->countNonVegDishes++;
        menu.insert(this->firstVeg, D);
    }
    this->countDishes++;
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
    if(this->countDishes == 0)
    {
        cout << "no dishes added for "<< this->cuisineName << " cuisine yet\n";
        return;
    }
    cout << "-------------------MENU-------------------\n";
    this->showNonVegMenu();
    this->showVegMenu();
}
void Cuisine::showVegMenu()
{
    if(this->countVegDishes == 0)
    {
        cout << "no veg dishes\n";
        return;
    }
    for(int i = 0; i < this->countVegDishes; i++)
    {
        ((this->firstVeg) + i)->showDishInfo();
    }
    return;
}
void Cuisine::showNonVegMenu()
{
    if(this->countNonVegDishes == 0)
    {
        cout << "no non-veg dishes\n";
        return;
    }
    for(auto it = menu.begin(); it < this->firstVeg; it++)
    {
        it->showDishInfo();
    }
    return;
}