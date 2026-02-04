#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int num = 0;

class Book
{
public:
    std::string name,author;
    int price, LPIN;
};
Book *Lib = nullptr;


int Search(Book Arr[], string Name)
{
    for(int i = 0 ; i < num ; i++)
    {
        if ((Arr[i].name) == Name)
        {
            return i;
        }
    }
    return -1;
}

void Issue_Book (Book Arr[], std::string Name, int LP)
{
    int ind{Search(Arr, Name)};
    if(ind == -1)
    {
        cout << "Book : " << Name << " not found in the Library" << endl;
        return;
    }
    if(Arr[ind].LPIN != 0)
    {
        cout << "Book : " << Name << " is already issued by patron " << Arr[ind].LPIN << endl << "can't be reissued unless returned" << endl;
        return;
    }
    Arr[ind].LPIN = LP;
    cout << "issue successful" << endl << "Book : " << Name << endl << "Issued by : " << LP << endl;
    return;
}
void Return_Book (Book Arr[], std::string Name, int LP)
{
    int ind{Search(Arr, Name)};
    if(ind == -1)
    {
        cout << "Book : " << Name << " not found in the Library" << endl;
        return;
    }
    if(Arr[ind].LPIN == 0)
    {
        cout << "Book : " << Name << " is not issued by anyone" << endl << "can't be returned unless issued" << endl;
        return;
    }
    if(Arr[ind].LPIN != LP)
    {
        cout << "Book : " << Name <<  " not issued by patron " << LP << endl << "issued by patron : " << Arr[ind].LPIN << endl << "can be returned only by the issuer" << endl;
        return ;
    }
    Arr[ind].LPIN = 0;
    cout << "return successful of book : " << Name << "by patron : " << Arr[ind].LPIN << endl;
    return;
}

int main()
{
    cout << "enter the number of books whose info are to be read from the file : ";
    cin >> num;
    ifstream fhand("data.txt");
    if(!(fhand.is_open()))
    {
        cout << "file could not be opened !!!" << endl;
        return 1;
    }
    Lib = new Book[num];
    for(int i = 0 ; i < num ; i++)
    {
        fhand >> Lib[i].name;
        fhand >> Lib[i].author;
        fhand >> Lib[i].price;
        fhand >> Lib[i].LPIN;
    }
    fhand.close();
    string bookname;
    bookname = "Atomic_Habits";

    //issuing available book
    Issue_Book( Lib , bookname, 12);

    //trying to issue already issued book
    Issue_Book( Lib , bookname, 15);

    //returning book by wrong patron
    Return_Book( Lib , bookname, 15);

    //returning book by correct patron
    Return_Book( Lib , bookname, 12);

    //issuing returned book
    Issue_Book( Lib , bookname, 15);

    //issuing non existing book
    bookname = "The_Alchemist"; 
    Issue_Book( Lib , bookname, 20);
    
    //returning non issued book
    bookname = "Deep_Work"; 
    Return_Book( Lib , bookname, 25);
    delete [] Lib;
    return 0;
}