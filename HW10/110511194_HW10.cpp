#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
    int ent[50] = {0}, oup[50][2] = {0};
    int md, n;
    string a = "N",b = "Count",c;

    cout << "Please enter mode : 1.input from file. 2. input from command." << endl;
    cin >> md;

    if(md == 1)
    {
        ifstream inp;

        cout << "Please input the name of the file." << endl;
        cin >> c;

        inp.open(c);

        inp >> n;
        for(int i = 1; i <= n; i++)
        {
            inp >> ent[i-1];
        }

        for(int j = 0; j < n-1; j++)
        {
            for(int i = n-1;i > j; i--)
            {
                if(ent[i] > ent[i-1])
                {
                    int temp;
                    temp = ent[i];
                    ent[i] = ent [i-1];
                    ent[i-1] = temp;
                }

            }

        }

        int t = 0;

        for(int i = 0, j = 1; i <= n-1; i++)
        {
            if(ent[i] == ent[i+1])
            {
                j++;
            }
            else
            {
                oup[t][0] = ent[i];
                oup[t][1] = j;
                j = 1;
                t++;
            }
        }
        cout << a << "     " << b << endl;

        for(int i = 0; i < t; i++)
        {
            for(int j = 0; j < 2; j++)
            {
                cout << left << setw(5) << oup[i][j] << " ";
            }
            cout << endl;
        }
        inp.close();
    }
    else
    {
        cin >> n;

        for(int i = 0; i < n; i++)
        {
            cin >> ent[i];
        }

        for(int j = 0; j < n-1; j++)
        {
            for(int i = n-1;i > j; i--)
            {
                if(ent[i] > ent[i-1])
                {
                    int temp;
                    temp = ent[i];
                    ent[i] = ent [i-1];
                    ent[i-1] = temp;
                }

            }

        }

        int t = 0;

        for(int i = 0, j = 1; i <= n-1; i++)
        {
            if(ent[i] == ent[i+1])
            {
                j++;
            }
            else
            {
                oup[t][0] = ent[i];
                oup[t][1] = j;
                j = 1;
                t++;
            }
        }

        cout << a << "     " << b << endl;

        for(int i = 0; i < t; i++)
        {
            for(int j = 0; j < 2; j++)
            {
                cout << left << setw(5) << oup[i][j] << " ";
            }
            cout << endl;
        }
    }



    return 0;
}
