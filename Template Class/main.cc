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
    IDCard<int> student(250103);
    IDCard<string> faculty("FACULTY876");
    IDCard<string> staff("sta65876");
    cout << "Faculty ID: " << faculty.showID() << endl;
    cout << "Staff ID: " << staff.showID() << endl;
    cout << "Student " << student.showID() << endl;
    return 0;
}