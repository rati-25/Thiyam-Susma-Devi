#include "classes.h"
#include <bits/stdc++.h>
using namespace std;

// function for dish class
Dish::Dish(string N = "not assigned", double P = 0.00) : dishName(N), dishPrice(P) {}
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
    std::cout << "Name  :" << this->dishName << endl;
    std::cout << "Price :" << this->dishPrice << endl;
}

// functions for cuisine class
Cuisine::Cuisine() : countDishes(0), countNonVegDishes(0), countVegDishes(0), firstVeg(menu.end()) {}
void Cuisine::addDish(Dish D)
{
}
void Cuisine::removeDish(Dish D)
{
}
void Cuisine::showMenu()
{
    if (this->countDishes == 0)
    {
        std::cout << "no dishes added for " << this->cuisineName << " cuisine yet\n";
        return;
    }
    std::cout << "-------------------MENU-------------------\n";
    this->showNonVegMenu();
    this->showVegMenu();
}
void Cuisine::showVegMenu()
{
    if (this->countVegDishes == 0)
    {
        std::cout << "no veg dishes\n";
        return;
    }
    for (int i = 0; i < this->countVegDishes; i++)
    {
        ((this->firstVeg) + i)->showDishInfo();
    }
    return;
}
void Cuisine::showNonVegMenu()
{
    if (this->countNonVegDishes == 0)
    {
        std::cout << "no non-veg dishes\n";
        return;
    }
    for (auto it = menu.begin(); it < this->firstVeg; it++)
    {
        it->showDishInfo();
    }
    return;
}

// course class functions
starter::starter(string N = "not assigned", double P = 0.00) : Dish(N, P), dishCourse("starter") {}
mainCourse::mainCourse(string N = "not assigned", double P = 0.00) : Dish(N, P), dishCourse("main course") {}
dessert::dessert(string N = "not assigned", double P = 0.00) : Dish(N, P), dishCourse("dessert") {}
void starter::showDishInfo()
{
    Dish::showDishInfo();
    std::cout << "Course: " << this->dishCourse << endl;
}
void mainCourse::showDishInfo()
{
    Dish::showDishInfo();
    std::cout << "Course: " << this->dishCourse << endl;
}
void dessert::showDishInfo()
{
    Dish::showDishInfo();
    std::cout << "Course: " << this->dishCourse << endl;
}

veg::veg(string N = "not assigned", double P = 0.00) : Dish(N, P), dishType("veg") {}
nonveg::nonveg(string N = "not assigned", double P = 0.00) : Dish(N, P), dishType("nonveg") {}
void veg::showDishInfo()
{
    Dish::showDishInfo();
    std::cout << "Type  : " << this->dishType << endl;
}
void nonveg::showDishInfo()
{
    Dish::showDishInfo();
    std::cout << "Type  : " << this->dishType << endl;
}

sweet::sweet(string N = "not assigned", double P = 0.00) : Dish(N, P), dishType("sweet") {}
sugarFree::sugarFree(string N = "not assigned", double P = 0.00) : Dish(N, P), dishType("sugar free") {}
void sweet::showDishInfo()
{
    Dish::showDishInfo();
    std::cout << "Type  : " << this->dishType << endl;
}
void sugarFree::showDishInfo()
{
    Dish::showDishInfo();
    std::cout << "Type  : " << this->dishType << endl;
}

nonvegStarter::nonvegStarter(string N = "not assigned", double P = 0.00) : starter(N, P), nonveg(N, P) {}
void nonvegStarter::showDishInfo()
{
    starter::showDishInfo();
    std::cout << "Type  : " << this->dishType << endl;
}
vegStarter::vegStarter(string N = "not assigned", double P = 0.00) : starter(N, P), veg(N, P) {}
void vegStarter::showDishInfo()
{
    starter::showDishInfo();
    std::cout << "Type  : " << this->dishType << endl;
}
nonvegMainCourse::nonvegMainCourse(string N = "not assigned", double P = 0.00) : mainCourse(N, P), nonveg(N, P) {}
void nonvegMainCourse::showDishInfo()
{
    mainCourse::showDishInfo();
    std::cout << "Type  : " << this->dishType << endl;
}
vegMainCourse::vegMainCourse(string N = "not assigned", double P = 0.00) : mainCourse(N, P), veg(N, P) {}
void vegMainCourse::showDishInfo()
{
    mainCourse::showDishInfo();
    std::cout << "Type  : " << this->dishType << endl;
}
sweetDessert::sweetDessert(string N = "not assigned", double P = 0.00) : dessert(N, P), sweet(N, P) {}
void sweetDessert::showDishInfo()
{
    dessert::showDishInfo();
    std::cout << "Type  : " << this->dishType << endl;
}
sugarFreeDessert::sugarFreeDessert(string N = "not assigned", double P = 0.00) : sugarFree(N, P), dessert(N, P) {}
void sugarFreeDessert::showDishInfo()
{
    dessert::showDishInfo();
    std::cout << "Type  : " << this->dishType << endl;
}