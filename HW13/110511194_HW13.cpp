#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

string* addEntry(string *dynamicArray, int &Size, string newEntry);
string* deleteEntry(string *dynamicArray, int &Size, string entryToDelete);
string* acts(string *dynamicArray, int &p);

int main()
{
    string *arr = new string[5];
    char c = 'a';
    int p = 5;
    cout << "Enter names (Seperate by space)" << endl;
    for(int i = 0; i < 5; i++)
        cin >> arr[i];
    while(1)
        arr= acts(arr,p);
    return 0;
}

string* addEntry(string *dynamicArray, int &Size, string newEntry)
{
    string *newArray = new string[Size+1];
    for(int i = 0; i < Size; i++)
        newArray[i] = dynamicArray[i];
    newArray[Size] = newEntry;
    Size++;
    delete [] dynamicArray;
    return newArray;
}

string* deleteEntry(string *dynamicArray, int &Size, string entryToDelete)
{
    int p = -1;
    for(int i = 0; i < Size; i++)
    {
        if(dynamicArray[i] == entryToDelete)
        {
            p = i;
            break;
        }
    }
    if(p < 0)
        return dynamicArray;
    string *newArray = new string[Size - 1];
    for(int i = 0; i < p; i++)
        newArray[i] = dynamicArray[i];
    for(int i = p; i < (Size-1);i++)
        newArray[i] = dynamicArray[i+1];
    Size--;
    delete [] dynamicArray;
    return newArray;
}

string* acts(string *dynamicArray, int &p)
{
    char act;
    string osc;
    cout << "Enter function : ";
    cin >> act;
    switch(act)
    {
        case 'a':
            {
                cout << "Enter name : ";
                cin >> osc;
                string *newArray = new string[p+1];
                newArray = addEntry(dynamicArray, p, osc);
                for(int i = 0; i < p; i++)
                    cout << newArray[i] << " ";
                cout << endl;
                return newArray;
                break;
            }
        case 'd':
            {
                cout << "Enter name : ";
                cin >> osc;
                string *newArray = new string[p];
                newArray = deleteEntry(dynamicArray, p, osc);
                for(int i = 0; i < p; i++)
                    cout << newArray[i] << " ";
                cout << endl;
                return newArray;
                break;
            }
            break;
        case 'x':
            exit(0);
            break;
        default:
            break;
    }
}
