#include <iostream>

using namespace std;

int main()
{
    double x1,y1,x2,y2,m,c;
    cin >> x1 >> y1 >> x2 >> y2;

    m=(y2-y1)/(x2-x1);

    c=y1-m*x1;
    cout << "y=" << m << "x+(" << c << ")" <<endl;

    return 0;
}
