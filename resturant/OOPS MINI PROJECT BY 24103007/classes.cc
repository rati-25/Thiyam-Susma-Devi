#include "classes.h"
#include <iostream>
using namespace std;

// function for dish class
Dish::Dish(string N, double P) : dishName(N), dishPrice(P) {}
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
Cuisine::Cuisine(string S) : countDishes(0), cuisineName(S) {}

void Cuisine::addDessert(dessert D)
{
    dmenu.push_back(D);
}
void Cuisine::addMainCouse(mainCourse M)
{
    mmenu.push_back(M);
}
void Cuisine::addStarter(starter S)
{
    smenu.push_back(S);
}
string Cuisine::getCuisineName()
{
    return this->cuisineName;
}
void Cuisine::showMenu()
{
    if(smenu.empty() && dmenu.empty() && mmenu.empty())
    {
        cout << "nothing in the menu for this cuisine!!!\n";
        return;
    }
    if(!smenu.empty())
    {
        for(auto it: smenu)
        {
            it.showDishInfo();
        }
    }
    if(!mmenu.empty())
    {
        for(auto it: mmenu)
        {
            it.showDishInfo();
        }
    }
    if(!dmenu.empty())
    {
        for(auto it: dmenu)
        {
            it.showDishInfo();
        }
    }
}

// course class functions
starter::starter(string N, double P) : Dish(N, P), dishCourse("starter") {}
mainCourse::mainCourse(string N, double P) : Dish(N, P), dishCourse("main course") {}
dessert::dessert(string N, double P) : Dish(N, P), dishCourse("dessert") {}
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

veg::veg(string N, double P) : Dish(N, P), dishType("veg") {}
nonveg::nonveg(string N, double P) : Dish(N, P), dishType("nonveg") {}
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

sweet::sweet(string N, double P) : Dish(N, P), dishType("sweet") {}
sugarFree::sugarFree(string N, double P) : Dish(N, P), dishType("sugar free") {}
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

nonvegStarter::nonvegStarter(string N, double P) : Dish(N, P), starter(N, P), nonveg(N, P) {}
void nonvegStarter::showDishInfo()
{
    starter::showDishInfo();
    std::cout << "Type  : " << this->dishType << endl;
}
vegStarter::vegStarter(string N, double P) : Dish(N, P), starter(N, P), veg(N, P) {}
void vegStarter::showDishInfo()
{
    starter::showDishInfo();
    std::cout << "Type  : " << this->dishType << endl;
}
nonvegMainCourse::nonvegMainCourse(string N, double P) : Dish(N, P), mainCourse(N, P), nonveg(N, P) {}
void nonvegMainCourse::showDishInfo()
{
    mainCourse::showDishInfo();
    std::cout << "Type  : " << this->dishType << endl;
}
vegMainCourse::vegMainCourse(string N, double P) : Dish(N, P), mainCourse(N, P), veg(N, P) {}
void vegMainCourse::showDishInfo()
{
    mainCourse::showDishInfo();
    std::cout << "Type  : " << this->dishType << endl;
}
sweetDessert::sweetDessert(string N, double P) : Dish(N, P), dessert(N, P), sweet(N, P) {}
void sweetDessert::showDishInfo()
{
    dessert::showDishInfo();
    std::cout << "Type  : " << this->dishType << endl;
}
sugarFreeDessert::sugarFreeDessert(string N, double P) : Dish(N, P), sugarFree(N, P), dessert(N, P) {}
void sugarFreeDessert::showDishInfo()
{
    dessert::showDishInfo();
    std::cout << "Type  : " << this->dishType << endl;
}

int input = 0;
vector<Cuisine> chart;
int cuisineIterator = 0;

void SHOWMENU()
{
    if(chart.empty())
    {
        cout << "no cuisines added yet. add something to start\n";
    }
    else
    {
        for(auto it : chart)
        {
            it.showMenu();
        }
    }
}
void inp()
{
    cout << "input : ";
    cin >> input;
    return;
}

void showCuisines()
{
    if(chart.empty())
    {
        cout << "cuisines added yet. add one cuisine to add dish to it\n";
    }
    else
    {
        for(int cuisineIterator = 0; cuisineIterator < chart.size(); cuisineIterator++)
        {
            cout << cuisineIterator + 1 << " " << chart[cuisineIterator].getCuisineName() << '\t';
        }
        cout << endl;
    }
}