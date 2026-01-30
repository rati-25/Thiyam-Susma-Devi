#include "lib.h"

using namespace std;

int Search(Book Arr[] = Lib, string Name="Humans")
{
    for(int i = 0 ; i < num ; i++)
    {
        if (*(Arr[i].name) == Name)
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
    cout << "return successful" << endl;
    return;
}