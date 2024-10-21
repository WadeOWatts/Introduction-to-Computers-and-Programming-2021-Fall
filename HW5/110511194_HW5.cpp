#include <iostream>

using namespace std;

int main()
{
    int b,c,d;

    for(c = 1;c <= 3 ; c++)
    {
        for(d = 1;d <= 9; d = d + 2)
        {
            b = 27 - 4 * c - d;

            if(b == c || b ==d || c == d)
            {
                continue;
            }

            if(b >= 0 && b <= 9)
            {
                break;
            }

        }
        if(c == 3)
        {
            break;
        }

    }


    cout << "The address is " << 3 * c << b << c << d << " Pennsylvania Avenue." << endl;
    return 0;
}
