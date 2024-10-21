#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

vector<string> split(string target, string delimiter);

int main()
{
    ifstream inp;
    ofstream oup;

    inp.open("hw12_input.txt");
    oup.open("hw12_output.txt");

    int c;
    string a, b, d;

    getline(inp, d);

    c = atoi(d.c_str());

    for(int i = 1; i <= c; i++)
    {
        getline(inp,a);
        getline(inp,b);
        vector<string> split1= split(a,b);

        for(int j = 0; j < split1.size(); j++)
        {

            cout << split1[j] << endl;
            oup << split1[j] << endl;
        }


    }


    inp.close();
    oup.close();

    return 0;
}

vector<string> split(string target, string delimiter)
{
    string e,h;
    vector<string> f;
    int x = 0;
    while(x >= 0)
    {
        e = target.substr(0,target.find(delimiter));

        h = h + e + " ";


        target = target.substr(target.find(delimiter) + delimiter.length());
        x = target.find(delimiter);

    }
    h = h + target;


    f.push_back(h);


    return f;
}
