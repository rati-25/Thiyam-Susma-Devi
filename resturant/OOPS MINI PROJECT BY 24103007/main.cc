#include "classes.h"
#include <iostream>

using namespace std;

int main()
{
    cout << "--------------------------------------------welcome to the dish management system--------------------------------------------\n";
    while (true)
    {
        cout << "\n1 to show menu     2 to add dish    3 to show cuisines    0 to exit\n";
        inp();
        if (input == 0)
            break;
        if (input == 1)
            SHOWMENU();
        if (input == 2)
        {
            showCuisines();
            cout << "1 to add a cuisine     2 to add a dish to the existing cuisine    0 to exit\n";
            inp();
            if (input == 1)
            {
                string N;
                cout << "enter cuisine name : ";
                cin.ignore();
                cin >> N;
                Cuisine C1(N);
                chart.push_back(C1);
                cout << "cuisine added to the chart successfully\n";
            }
            if (input == 2)
            {
                cout << "enter the index of the cuisine : ";
                inp();
                cuisineIterator = input - 1;
                cout << "enter the course of the dish : \n";
                cout << "1 starter  2 main course   3 dessert\n";
                inp();
                if (input == 3)
                {
                    cout << "1 sweet    2 sugar free\n";
                    inp();
                    string N;
                    double P;
                    cin.ignore();
                    cout << "name : ";
                    cin >> N;
                    cout << "price :";
                    cin >> P;
                    if (input == 1)
                    {
                        sweetDessert s1(N, P);
                        chart[cuisineIterator].addDessert(s1);
                    }
                    else
                    {
                        sugarFreeDessert s1(N, P);
                        chart[cuisineIterator].addDessert(s1);
                    }
                    cout << "added the dessert\n";
                }
                else if (input == 2)
                {
                    cout << "1 veg    2 non veg\n";
                    inp();
                    string N;
                    double P;
                    cin.ignore();
                    cout << "name : ";
                    cin >> N;
                    cout << "price :";
                    cin >> P;
                    if (input == 1)
                    {
                        vegMainCourse s1(N, P);
                        chart[cuisineIterator].addMainCouse(s1);
                    }
                    else
                    {
                        nonvegMainCourse s1(N, P);
                        chart[cuisineIterator].addMainCouse(s1);
                    }
                    cout << "added the main course\n";
                }
                else
                {
                    cout << "1 veg    2 non veg\n";
                    inp();
                    string N;
                    double P;
                    cin.ignore();
                    cout << "name : ";
                    cin >> N;
                    cout << "price :";
                    cin >> P;
                    if (input == 1)
                    {
                        vegStarter s1(N, P);
                        chart[cuisineIterator].addStarter(s1);
                    }
                    else
                    {
                        nonvegStarter s1(N, P);
                        chart[cuisineIterator].addStarter(s1);
                    }
                    cout << "added the starter\n";
                }
            }
            if (input == 0)
            {
                continue;
            }
        }
        if (input == 3)
        {
            showCuisines();
        }
    }
}