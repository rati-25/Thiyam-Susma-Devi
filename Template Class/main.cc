#include <iostream>

using namespace std;

template <class T>
class IDCard
{
    T ID;
public:
    IDCard(T i):ID(i)
    {
        return;
    }
    T showID()
    {
        return this->ID;
    }
};

int main()
{
    IDCard<int> student(24103007);
    IDCard<string> faculty("fac1234");
    IDCard<string> staff("STA123456");
    cout << "Faculty ID: " << faculty.showID() << endl;
    cout << "Staff ID: " << staff.showID() << endl;
    cout << "Student " << student.showID() << endl;
    return 0;
}