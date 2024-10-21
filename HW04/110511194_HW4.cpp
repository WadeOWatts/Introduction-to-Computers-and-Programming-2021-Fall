#include <iostream>

using namespace std;

int main()
{
    int m,d;
    while(1)
    {
        cout << "input birthday: ";
        cin >> m >> d;
        cout << "horoscope: ";
        switch(m)
        {
            case 1:
                if(d <= 19 && d > 0)
                {
                    cout << "Capricorn.\n";
                }
                else if(d >=20 && d <= 31)
                {
                    cout << "Aquarius.\n";
                }
                else{
                    cout << "It is not a possible birthday.";
                }
                break;
            case 2:
                if(d <= 18 && d > 0)
                {
                    cout << "Aquarius.\n";
                }
                else if(d >=19 && d <= 28)
                {
                    cout << "Pisces.\n";
                }
                else{
                    cout << "It is not a possible birthday.";
                }
                break;
            case 3:
                if(d <= 20 && d > 0)
                {
                    cout << "Pisces.\n";
                }
                else if(d >=21 && d <= 31)
                {
                    cout << "Aries.\n";
                }
                else{
                    cout << "It is not a possible birthday.";
                }
                break;
            case 4:
                if(d <= 19 && d > 0)
                {
                    cout << "Aries.\n";
                }
                else if(d >=20 && d <= 30)
                {
                    cout << "Taurus.\n";
                }
                else{
                    cout << "It is not a possible birthday.";
                }
                break;
            case 5:
                if(d <= 20 && d > 0)
                {
                    cout << "Taurus.\n";
                }
                else if(d >=21 && d <= 31)
                {
                    cout << "Gemini.\n";
                }
                else{
                    cout << "It is not a possible birthday.";
                }
                break;
            case 6:
                if(d <= 21 && d > 0)
                {
                    cout << "Gemini.\n";
                }
                else if(d >=22 && d <= 30)
                {
                    cout << "Cancer.\n";
                }
                else{
                    cout << "It is not a possible birthday.";
                }
                break;
            case 7:
                if(d <= 22 && d > 0)
                {
                    cout << "Cancer.\n";
                }
                else if(d >=23 && d <= 31)
                {
                    cout << "Leo.\n";
                }
                else{
                    cout << "It is not a possible birthday.";
                }
                break;
            case 8:
                if(d <= 22 && d > 0)
                {
                    cout << "Leo.\n";
                }
                else if(d >=23 && d <= 31)
                {
                    cout << "Virgo.\n";
                }
                else{
                    cout << "It is not a possible birthday.";
                }
                break;
            case 9:
                if(d <= 22 && d > 0)
                {
                    cout << "Virgo.";
                }
                else if(d >=23 && d <= 30)
                {
                    cout << "Libra.\n";
                }
                else{
                    cout << "It is not a possible birthday.";
                }
                break;
            case 10:
                if(d <= 22 && d > 0)
                {
                    cout << "Libra.\n";
                }
                else if(d >=23 && d <= 31)
                {
                    cout << "Scorpio.\n.";
                }
                else{
                    cout << "It is not a possible birthday.";
                }
                break;
            case 11:
                if(d <= 21 && d > 0)
                {
                    cout << "Scorpio.\n";
                }
                else if(d >=22 && d <= 30)
                {
                    cout << "Sagittarius.\n";
                }
                else{
                    cout << "It is not a possible birthday.";
                }
                break;
            case 12:
                if(d <= 21 && d > 0)
                {
                    cout << "Sagittarius.\n";
                }
                else if(d >=22 && d <= 31)
                {
                    cout << "Capricorn.\n";
                }
                else{
                    cout << "It is not a possible birthday.";
                }
            break;
            default:
                cout << "It is not a possible birthday.";
        }
        if(m<0)
        {
            break;
        }
    }
    return 0;
}
