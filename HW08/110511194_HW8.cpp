#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{
    ifstream inp;
    ofstream oup;
    string str;
    char ch[100];
    int i = 1;

    inp.open("input.txt");
    oup.open("output.txt");

    while(!inp.eof())
    {
        inp.getline(ch,100);



        int j;
        for(j = 0; ch[j] == ' ' ;j++);

        for(int n = 0; n + j <= 100 ;n++)
        {
            ch[n] = ch [n + j];
        }

        oup << setw(3) << i << ": " << ch << endl;

        i++;
    }

    inp.close();
    oup.close();

    return 0;
}
