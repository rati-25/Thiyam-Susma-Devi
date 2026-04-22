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

public:
    Dish(string N = "not assigned", double P = 0.00);
    double getDishPrice();
    string getDishName();
    void setDishPrice(double P);
    virtual void showDishInfo();
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

public:
    starter(string N = "not assigned", double P = 0.00);
    void showDishInfo();
};
class mainCourse : public Dish
{
protected:
    const string dishCourse;

public:
    mainCourse(string N = "not assigned", double P = 0.00);
    void showDishInfo();
};
class dessert : public Dish
{
protected:
    const string dishCourse;

public:
    dessert(string N = "not assigned", double P = 0.00);
    void showDishInfo();
};

class nonveg : public Dish
{
protected:
    const string dishType;

public:
    nonveg(string N = "not assigned", double P = 0.00);
    void showDishInfo();
};
class veg : public Dish
{
protected:
    veg(string N = "not assigned", double P = 0.00);
    const string dishType;

public:
    void showDishInfo();
};
class sweet : public Dish
{
protected:
    const string dishType;

public:
    sweet(string N = "not assigned", double P = 0.00);
    void showDishInfo();
};
class sugarFree : public Dish
{
protected:
    const string dishType;

public:
    sugarFree(string N = "not assigned", double P = 0.00);
    void showDishInfo();
};

class nonvegStarter : virtual public nonveg, virtual public starter
{
public:
    nonvegStarter(string N = "not assigned", double P = 0.00);
    void showDishInfo();
};
class nonvegMainCourse : virtual public nonveg, virtual public mainCourse
{
public:
    nonvegMainCourse(string N = "not assigned", double P = 0.00);
    void showDishInfo();
};
class vegStarter : virtual public veg, virtual public starter
{
public:
    vegStarter(string N = "not assigned", double P = 0.00);
    void showDishInfo();
};
class vegMainCourse : virtual public veg, virtual public mainCourse
{
public:
    vegMainCourse(string N = "not assigned", double P = 0.00);
    void showDishInfo();
};
class sweetDessert : virtual public sweet, virtual public dessert
{
public:
    sweetDessert(string N = "not assigned", double P = 0.00);
    void showDishInfo();
};
class sugarFreeDessert : virtual public sugarFree, virtual public dessert
{
public:
    sugarFreeDessert(string N = "not assigned", double P = 0.00);
    void showDishInfo();
};

#endif