#ifndef CLASSES_H
#define CLASSES_H
#include <string>
#include <vector>
using namespace std;

vector<Dish> starters;
vector<Dish> mainCourses;
vector<Dish> desserts;
vector<Dish> sideItems;
vector<Drink> drinks;

class Dish
{
protected:
    const string dishName;
    double dishPrice;

public:
    Dish(string N = "not assigned", double P = 0.00);
    double getDishPrice();
    string getDishName();
    void setDishPrice(double P);
    void showDishInfo();
};

class Drink
{
protected:
    const string drinkName;
    double drinkPrice;

public:
    Drink(string N = "not assigned", double P = 0.00) : drinkName(N), drinkPrice(P) {}
    double getDrinkPrice();
    string getDrinkName();
    void setDrinkPrice(double P);
};

class Cuisine
{
protected:
    const vector<Dish>::iterator firstVeg;
    int countDishes;
    int countVegDishes;
    int countNonVegDishes;
    string cuisineName;
    vector<Dish> menu;

public:
    Cuisine();
    void addDish(Dish D);
    void removeDish(Dish D);
    void showMenu();
    void showVegMenu();
    void showNonVegMenu();
};


class starter : public Dish
{
protected:
    const string dishCourse;
};
class mainCourse : public Dish
{
protected:
    const string dishCourse;
};
class dessert : public Dish
{
protected:
    const string dishCourse;
};


class nonveg : public Dish
{
protected :
    const string dishType;
};
class veg : public Dish
{
protected :
    const string dishType;
};

#endif