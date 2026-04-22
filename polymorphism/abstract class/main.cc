#include <iostream>
using namespace std;

class animal{
public:
    virtual void makeSound()
    {
        cout << "animal making sound\n";
    }
    virtual void travel()
    {
        cout << "animal travelling\n";
    }
};

class cat : public animal{
    string name;
public:
    cat(string s): name(s){}
    void makeSound()
    {
        cout << "meow\n";
    }
    void travel()
    {
        cout << "jumping silentlt\n";
    }
};

class bird : public animal{
    string name;
public:
    bird(string s): name(s){}
    void makeSound()
    {
        cout << "chirping\n";
    }
    void travel()
    {
        cout << "flying\n";
    }
};

int main()
{
    cat C1("Oggy");
    bird B1("bard");
    animal* aptr = nullptr;
    aptr = &C1;
    aptr->makeSound();
    aptr->travel();
    aptr = &B1;
    aptr->makeSound();
    aptr->travel();
    return 0;
}