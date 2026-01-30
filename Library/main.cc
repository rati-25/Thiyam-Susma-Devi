#include "lib.h"
#include <fstream>

using namespace std;

int main()
{
    cout << "enter the number of books whose info are to be read from the file : ";
    cin >> num;
    string filename;
    getline(cin, filename );
    ifstream fhand(filename);
    if(!(fhand.is_open()))
    {
        cout << "file could not be opened !!!" << endl;
        return 1;
    }
    Book *Lib = new Book[num];
    for(int i = 0 ; i < num ; i++)
    {
        getline(fhand, *(Lib[i].name));
        getline(fhand, *(Lib[i].author));
        fhand >> Lib[i].price;
        fhand >> Lib[i].LPIN;
    }
    fhand.close();
    string bookname;
    bookname = "Atomic_Habits";
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