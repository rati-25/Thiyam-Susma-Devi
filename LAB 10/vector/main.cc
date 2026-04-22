#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cout << "enter the number of elements in the vector : ";
    cin >> n;
    vector<int> vec(n);
    int i{0};
    cout << "enter the numbers to be stored in the vector\n";
    while(i < n)
    {
        cin >> vec[i++];
    }
    cout << "enter the number to be foudn inth3e vector: ";
    cin >> i;
    for(int j = 0; j < n; j++)
    {
        if(vec[j] == i)
        {
            cout << "found the number " << i << " at index " << j << endl;
            return 0;
        }
    }
    cout << "number not found\n";
    return 0;
}