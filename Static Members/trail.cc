#include<iostream>

using namespace std;

class all{
    static int count;
    double a,b,x;
public:
    int getcount(){
        return count;
    }
};

int all::count = 4;

int main()
{
    all a;
    cout << a.getcount() << endl;
}