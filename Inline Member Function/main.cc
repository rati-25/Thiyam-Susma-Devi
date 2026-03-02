#include <iostream>

using namespace std;

class Student
{
    double m1,m2,m3;
    char grade;
    double total_m()
    {
        return m1+m2+m3;
    }
    void calc_grade()
    {
        this->grade = 'C';
        if(avg_m()>=80)
            this->grade='A';
        else if(avg_m()>=60)
            this->grade='B';
        return;
    }
    public:
    Student(double a = 0, double b = 0, double c = 0):m1(a),m2(b),m3(c)
    {
        this->calc_grade();
        return;
    }
    double avg_m();
    void display()
    {
        cout << "Total Marks : " << total_m() << endl;
        cout << "Average Marks : " << avg_m() << endl;
        cout << "Grade " << this->grade << endl;
        return;
    }

};
double Student::avg_m()
{
    return this->total_m()/3;
}
int main()
{
    double a,b,c;
    cout << "enter the marks of the three subjects : " ;
    cin >> a >> b >> c;
    Student Rati(a,b,c);
    Rati.display();
    return 0;
}