#include <iostream>
#include <cassert>

using namespace std;

void f0(double& price, double discount);
void f1(double& price, double discount);

int main()
{
    bool type;
    double price, discount;
    cin >> price >> discount >> type;

    if(type == 0)
    {
        f0(price, discount);
    }
    else
    {
        f1(price, discount);
    }

    return 0;
}

void f0(double& price, double discount)
{
    assert(discount >= 0);
    price = price - price * (discount/100.0);
    assert(price > 0);
    cout << price << endl;
}

void f1(double& price, double discount)
{
    assert(discount >= 0);
    price = price - discount;
    assert(price > 0);
    cout << price << endl;
}
