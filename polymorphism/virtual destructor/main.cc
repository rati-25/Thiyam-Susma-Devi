#include <iostream>

using namespace std;

class Shape{
public:
    int* IPTR;
    Shape(int n = 10)
    {
        IPTR = new int[n];
        cout << "allocated the dynamic integral array\n";
    }
    ~Shape()
    {
        // delete IPTR;
        cout << "successfully deallocated the dynamic integral array\n";
    }
};

class Circle : public Shape{
public:
    char* CPTR;
    Circle(int n = 10, int c = 10): Shape(n)
    {
        CPTR = new char[c];
        cout << "allocated the dynamic character array\n";
    }
    ~Circle()
    {
        // delete CPTR;
        cout << "succefully deallocated the dynamic character array\n";
    }
};

int main()
{
    Shape* sptr;
    Circle C1(10, 10);
    sptr = &C1;
    delete sptr;
}