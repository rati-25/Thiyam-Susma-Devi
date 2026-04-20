#ifndef CLASSES_H
#define CLASSES_H
#include <string>
#include <vector>
using namespace std;

class Dish
{
protected:
    const string dishName;
    double dishPrice;
    const string dishType;
public:
    Dish(string N = "not assigned", double P = 0.00): dishName(N), dishPrice(P){}
    string getDishType();
    double getDishPrice();
    string getDishName();
    void setDishPrice(double P);
};
class Drink
{
protected:
    const string drinkName;
    double drinkPrice;
public:
    Drink(string N = "not assigned", double P = 0.00): drinkName(N), drinkPrice(P){}
    double getDrinkPrice();
    string getDrinkName();
    void setDrinkPrice(double P);
};
class Cuisine 
{
protected:
    string cuisineName;
    vector<Dish> menu;
public:
    void addDish(Dish D);
    void removeDish(Dish D);
    void showMenu();
};
#endif