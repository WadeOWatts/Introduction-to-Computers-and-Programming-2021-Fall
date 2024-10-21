#include <iostream>

using namespace std;

int main()
{
    int r,p;
    cout << "Please enter the maximum room capacity." << endl;
    cin >> r;
    cout << "Please enter number of people." << endl;
    cin >> p;

    do{

        if(r>=p){
            cout << "It is legal to held the meeting." << endl;
            cout << r-p << " additional people are legal to attend." << endl;
        }
        else{
            cout << "The meeting cannot be held as planned due to fire regulations." << endl;
            cout << p-r << " people must be excluded in order to meet the fire regulations." << endl;
        }

        cout << "Please enter the maximum room capacity." << endl;
        cin >> r;
        cout << "Please enter number of people." << endl;
        cin >> p;

    }while(r >= 0 && p >= 0);

    return 0;
}
