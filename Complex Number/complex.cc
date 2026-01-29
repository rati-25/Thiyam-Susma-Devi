#include "complex.h"
#include <iostream>
#include <cmath>

using namespace std;

typedef struct Complex
{
    //date
    double real{0}, img{0};

    //functions
    double magnitude()
    {
        return sqrt(pow(real,2)+pow(img,2));
    }
    Complex Sum(Complex const &a)
    {
        Complex sum{this->real+a.real , this->img+a.img};
        return sum;
    }
};