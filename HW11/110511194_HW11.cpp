#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>

using namespace std;

int main()
{
    string first, test, punc(",;:.?!\" ");
    ifstream in;
    ofstream ou;

    in.open("hw11_input.txt");
    ou.open("hw11_output.txt");

    while(!in.eof())
    {
        int a = 0, b = 0, c = -1;
        getline(in, first);
        for(int i = 0; i <= first.length(); i++)
        {
            test = first.substr(i,1);

            a = punc.find(test);

            if(a >= 0)
            {
                if(b == 4)
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
                    if(isupper(first[i-4]))
                    {
                        cout << "Love" ;
                        ou << "Love";
                    }
                    else
                    {
                        cout << "love";
                        ou << "love" << test;
                    }
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
                    cout << test ;


                    c = i;
                    b = 0;
                }
                else
                {
                    for(int x = c + 1; x <= i; x++)
                    {
                        cout << first[x];
                        ou << first[x];
                    }
                    c = i;
                    b = 0;
                }
            }
            else
            {
                if(test == "\'")
                    continue;
                b++;
            }

        }
        cout << endl;
        ou << endl;
    }

    in.close();
    ou.close();

    return 0;
}
