#include <iostream>
#include <fstream>
#include <ctype.h>

using namespace std;

int main()
{
    ifstream input;
    ofstream output;
    char ch;
    int i = 0, j = 0, k = 0;

    input.open("input.txt");
    output.open("output.txt");

    input.get(ch);
    for(i = 0; !input.eof(); i++)
    {
        if((ch != ' ') && (ch != '\t') && (ch != '\n') && (ch != '\v') && (ch != '\f') && (ch != '\r'))
        {
            j++;
            if(isalpha(ch))
            {
                k++;
            }
        }
        input.get(ch);
    }

    output << "total number of character : " << i << endl;
    output << "total number of non-whitespace character : " << j << endl;
    output << "total number of letter : " << k << endl;

    input.close();
    output.close();

    return 0;
}
