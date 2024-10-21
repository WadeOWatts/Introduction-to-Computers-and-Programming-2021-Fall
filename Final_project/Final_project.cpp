#include <iostream>
#include <windows.h>
#include <iomanip>
#include <cstdlib>
#include <conio.h>
#include <ctime>
#include <stdlib.h>

int const smallcolumn = 23;
int const smallrow = 12;
int const largecolumn = 43;
int const largerow = 22;
char wall = 'l';//enemies should move right first
int p = 1;//hard version, enemies moving

void remov();//remove the underbar
void gotoxy(int xpos, int ypos);//clean the screen
void start();//the start picture
void choose(int&);//choose the difficulty and the size
int win();//win picture
int lose();//lose picture
void game_screen(char[][smallcolumn], int, int&);//how the game be like
void press(char[][smallcolumn],int,int,int&);//detect whether player press the key
void moveleft(char[][smallcolumn],int,int,int&);//when player press A
void moveright(char[][smallcolumn],int,int,int&);//when player press D
void shoot(char[][smallcolumn],int,int,int&);//when player press S
void search_n_move(char[][smallcolumn],int,int,int&);//rearrange the screen but not cout
void bomb(char[][smallcolumn],int);//enemies bomb
void enemy_moves(char[][smallcolumn],int,char&);//enemies move horizontally
void enemy_move_downward(char[][smallcolumn],int,int,int&);//hard version, enemies move downward
int count_U(char[][smallcolumn],int);//count the number of U
void printout(char[][smallcolumn],int,int&);//print out
void check_U_move_downward_or_not(int &iwin, int &p, char display[][smallcolumn], int r, int e ,int &o);
int easysmall(int,int&);// enemy's lives, our lives

int mediumsmall(int,int&);// enemy's lives, our lives

int hardsmall(int,int,int&);// enemy's lives, our lives



using namespace std;

int main()
{
    remov();
    start();
    gotoxy(0,0);
    for(int i = 1;i < 20; i ++)
    {
        for(int j = 1; j <= 12; j++)
        {
            cout << "\t";
        }
        cout << endl;
    }
    gotoxy(0,0);

    int play = 1;
    while(play != 0)
    {
        int kachimake = 0;
        choose(kachimake);
        if(kachimake == 1)
        {
            gotoxy(0,0);
            for(int i = 1;i <= 22; i ++)
            {
                for(int j = 1;j <= 43; j ++)
                {
                    cout << "  ";
                }
                cout << endl;
            }
            gotoxy(0,0);
            play = win();
        }

        else
        {
            gotoxy(0,0);
            for(int i = 1;i <= 22; i ++)
            {
                for(int j = 1;j <= 43; j ++)
                {
                    cout << "  ";
                }
                cout << endl;
            }
            gotoxy(0,0);
            play = lose();
        }
        gotoxy(0,0);
        for(int i = 1;i < 20; i ++)
        {
            for(int j = 1; j <= 12; j++)
            {
                cout << "\t";
            }
            cout << endl;
        }
        gotoxy(0,0);
    }
    gotoxy(0,0);
    for(int i = 1;i < 20; i ++)
    {
        for(int j = 1; j <= 12; j++)
        {
            cout << "\t";
        }
        cout << endl;
    }
    gotoxy(0,0);

    return 0;
}



void remov()
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO CursorInfo;
    GetConsoleCursorInfo(handle, &CursorInfo);
    CursorInfo.bVisible = false;
    SetConsoleCursorInfo(handle, &CursorInfo);
}

void gotoxy(int xpos, int ypos)
{
    COORD scrn;
    HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
    scrn.X = xpos;
    scrn.Y = ypos;
    SetConsoleCursorPosition(hOuput, scrn);
}

void start()
{
    gotoxy(0,2);
    cout << setw(15) << "Hello!!" << endl;
    cout << endl;
    cout << " Play rules: a = left" << endl;
    cout << setw(22) << "d = right" << endl;
    cout << setw(22) << "s = shoot" << endl;
    for(int i = 1; i<= 3; i++)
    {
        cout << endl;
    }
    cout << " Press any key to start..." << endl;
    cout << endl;
    cout << " Made by 110511194.";
    getch();
}

void choose(int &shouhai)
{
    char gamedifficulty,d;
    gotoxy(0,4);
    cout << "Please choose the difficulty of the game." << endl;
    cout << endl;
    cout << "Press E for easy" << endl;
    cout << setw(18) << "M for medium" << endl;
    cout << setw(16) << "H for hard" << endl;
    cout << endl;
    cout << "Difficult: ";
    cin >> d;
    gamedifficulty = tolower(d);

    switch(gamedifficulty)
    {
        case 'e':
            {
                int e = 1, o = 2;
                shouhai = easysmall(e,o);
                return;
                break;
            }
        case 'm':
            {
                int e = 1, o = 1;
                shouhai = mediumsmall(e,o);
                return;
                break;
            }

        case 'h':
            {
                int e = 2, o = 1;
                shouhai = hardsmall(e,o,p);
                return;
                break;
            }
        default:
            break;
    }
}

int win()
{
    char again;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
    gotoxy(0,5);
    cout << setw(20) << "Congratulations!!" << endl;
    cout << endl;
    cout << setw(16) << "You won!!" << endl;
    Sleep(3000);
    gotoxy(0,5);
    cout << "Do you want to play again?" << endl;
    cout << endl;
    cout << "Press Y for yes and N for no. " ;
    cin >> again;
    if(again == 'Y' || again == 'y')
    {
        return 1;
    }
    else
    {
        gotoxy(0,0);
        for(int i = 1;i < 20; i ++)
        {
            for(int j = 1; j <= 12; j++)
            {
                cout << "\t";
            }
            cout << endl;
        }
        return 0;
    }
}

int lose()
{
    char again;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
    gotoxy(0,5);
    cout << setw(17) << "Game over!!" << endl;
    cout << endl;
    cout << setw(21) << "You can try again!!" << endl;
    Sleep(3000);
    gotoxy(0,5);
    cout << "Do you want to play again?" << endl;
    cout << endl;
    cout << "Press Y for yes and N for no. ";
    cin >> again;
    if(again == 'Y' || again == 'y')
        return 1;
    else
    {
        gotoxy(0,0);
        for(int i = 1;i < 20; i ++)
        {
            for(int j = 1; j <= 12; j++)
            {
                cout << "\t";
            }
            cout << endl;
        }
        gotoxy(0,0);
        return 0;
    }
}

void game_screen(char display[][smallcolumn],int r, int& o)
{

    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < smallcolumn; j++)
        {
            if(i == 0 || i == r-1)
            {
                display[i][j] = '_';
            }
            else if(j == 0 || (j == smallcolumn-1))
            {
                display[i][j] = '|';
            }
        }
    }

    for(int i = 1; i <= 2; i++)
    {
        for(int j = 1; j < 22; j++)
        {
            if((i == 1) && (j > 3) && (j <= 18))
            {
                display[i][j] = 'U';
            }
            else if((i == 2) && (j > 4) && (j <= 17))
            {
                display[i][j] = 'U';
            }
        }
    }

    for(int i = 9; i < 11; i++)
    {
        for(int j = 10; j <= 12; j++)
        {
            if((i == 9) && (j == 11))
            {
                display[i][j] = 'T';
            }
            else if(i == 10)
            {
                display[i][j] = 'T';
            }
        }
    }
    for(int i = 0; i < 12; i++)
    {
        for(int j = 0; j < 23; j++)
        {
            if(display[i][j] == '0')
            {
                display[i][j] = ' ';
            }
        }
    }

    gotoxy(0,0);
    printout(display,r,o);
}

void press(char adisplay[][smallcolumn],int r,int e, int& o)
{
    if(kbhit())
    {

        char hit = getch();
        if((hit == 'a') || (hit == 'A'))
        {
            moveleft(adisplay,r,e,o);
        }
        else if((hit == 'd') || (hit == 'D'))
        {
            moveright(adisplay,r,e,o);
        }
        else if((hit == 's') || (hit == 'S'))
        {
            shoot(adisplay,r,e,o);
        }
   }
    return;
}

void moveleft(char bdisplay[][smallcolumn],int r, int e, int& o)
{
    for(int j = 2; j < smallcolumn-2; j++)
        {
            if(bdisplay[r-3][j] == 'T')
            {
                if((bdisplay[r-3][j-1] == '*')||(bdisplay[r-3][j-2] == '*'))
                {
                    o--;
                    if(o == 0)
                    {
                        return;
                    }
                }
                else if(bdisplay[r-3][j-2] == '|')
                {
                    break;
                }
                else
                {
                    bdisplay[r-3][j-1] = 'T';
                    bdisplay[r-3][j] = ' ';
                    bdisplay[r-2][j-2] = 'T';
                    bdisplay[r-2][j-1] = 'T';
                    bdisplay[r-2][j] = 'T';
                    bdisplay[r-2][j+1] = ' ';
                }
                break;
            }
        }
        return;
}
void moveright(char display[][smallcolumn],int r, int e, int& o)
{
    for(int j = 2; j < smallcolumn-2; j++)
    {
        if(display[r-3][j] == 'T')
        {
            if((display[r-3][j+1] == '*') || (display[r-3][j+2] == '*'))
            {
                o--;
                if(o == 0)
                {
                    return;
                }
            }
            else if(display[r-3][j+2] == '|')
            {

            }
            else
            {
                display[r-3][j+1] = 'T';
                display[r-3][j] = ' ';
                display[r-2][j+2] = 'T';
                display[r-2][j+1] = 'T';
                display[r-2][j] = 'T';
                display[r-2][j-1] = ' ';
            }
            break;
        }
    }
    return;
}
void shoot(char display[][smallcolumn],int r,int e, int& o)
{
    for(int j = 2; j < smallcolumn-2; j++)
    {
        if(display[r-3][j] == 'T')
        {
            if(display[r-4][j] == '*')
            {
                display[r-4][j] = ' ';
            }
            else if((display[r-5][j] == '*') && (display[r-4][j] == ' '))
            {
                display[r-5][j] = ' ';
            }
            else if((display[r-5][j] == '*') && (display[r-4][j] == '*'))
            {
                display[r-4][j] = ' ';
            }
            else if((display[r-3][j-1] == '*') || (display[r-3][j+1] == '*'))
            {
                o--;
                if(o == 0)
                {
                    return;
                }
                display[r-3][j-1] = ' ';
                display[r-3][j+1] = ' ';
            }
            else if(display[r-4][j] == '^')
            {
                display[0][0] = '9';
            }
            else
            {
                display[r-4][j] = '9';
            }
            break;
        }

    }
    return;
}

void search_n_move(char display[][smallcolumn],int r, int e, int& o)
{
    for(int i = 1; i < (r-1); i++)
    {
        for(int j = 1; j < (smallcolumn-1); j++)
        {
            if(display[i][j] == '*')
            {
                if(display[i+1][j] == 'T')
                {
                    o--;
                    if(o == 0)
                    {
                        return;
                    }
                    display[i][j] = ' ';
                }
                else if(display[i+1][j] == '9')
                {
                    display[i][j] = ' ';
                    display[i+1][j] = ' ';
                    if(display[0][0] == '9')
                    {
                        display[0][0] = '_';
                        display[i+1][j] = '9';
                    }
                }
                else if(display[i-1][j] == '7')
                {
                    int p = 3;
                    for(int k = i+1; k < 12; k++,p++)
                    {
                        if(display[k][j] != '*')
                        {
                            break;
                        }
                    }
                    if(display[i+p-2][j] ==  '_')
                    {
                        display[i][j] = ' ';
                        for(int k = i; k < (i+p-2); k++)
                        {
                            display[k][j] = '*';
                        }
                    }
                    else if(display[i+p-2][j] == '^')
                    {
                        for(int y = i-1; y < (i+p-2); y++)
                        {
                            display[y][j] = '*';
                        }
                        display[i+p-2][j] = ' ';

                    }
                    else if((display[i+p-2][j] == ' ') && (display[i+p-1][j] == '^'))
                    {
                        for(int y = i-1; y < (i+p-2); y++)
                        {
                            display[y][j] = '*';
                        }
                        display[i+p-2][j] = ' ';
                        display[i+p-1][j] = ' ';
                    }
                    else
                    {
                        for(int u = i-1; u <= (i-2+p); u++)
                        {
                            display[u][j] = '*';
                        }
                    }
                }
                else if(display[i+1][j] == '_')
                {
                    if(display[i-1][j] == ' ')
                    {
                        display[i][j] = ' ';
                    }
                }
                else if(display[i+1][j] == '*')
                {
                    if(display[i-1][j] == '*')
                    {

                    }
                    else
                    {
                        display[i][j] = ' ';
                        display[i+1][j] = '7';
                    }
                }
                else if(display[i-1][j] == '7')
                {
                    display[i][j] = '7';
                }
                else if((display[i+1][j] == '^') && (display[i+2][j] == ' '))
                {
                    display[i][j] = ' ';
                    display[i+1][j] = ' ';
                }
                else if((display[i+2][j] == '^') && (display[i+1][j] == ' '))
                {
                    display[i][j] = ' ';
                    display[i+2][j] = ' ';
                }
                else if((display[i+1][j] == '^') && (display[i+2][j] == '^'))
                {
                    display[i][j] = ' ';
                    display[i+1][j] = '2';
                    display[i+2][j] = ' ';
                }
                else if(display[i-1][j] == '*')
                {

                }
                else
                {
                    display[i][j] = ' ';
                    display[i+1][j] = '8';
                }
            }
            else if(display[i][j] == '2')
            {
                display[i][j] = '^';
            }
            else if(display[i][j] == '8')
            {
                display[i][j]  = '*';
            }
            else if(display[i][j] == '^')
            {
                if(i == 1)
                {
                    display[i][j] = ' ';
                }
                else if(display[i-1][j] == '*' ||display[i-1][j] == '^')
                {

                }
                else if((display[i+1][j] == 'T')&&(display[0][0]) == '9')
                {
                    display[i][j] = '^';
                    display[i-1][j] = '^';
                    display[0][0] = '_';
                }
                else
                {
                    display[i][j] = ' ';
                    display[i-1][j] = '^';
                }

            }
            else if(display[i][j] == 'U')
            {
                if(display[i+1][j] == '^')
                {
                    if(e == 1)
                    {
                        display[i][j] = ' ';
                        display[i+1][j] = ' ';
                    }
                    else
                    {
                        display[i][j] = 'n';
                        display[i+1][j] = ' ';
                    }

                }
            }
            else if(display[i][j] == 'n')
            {
                if(display[i+1][j] == '^')
                {
                        display[i][j] = ' ';
                        display[i+1][j] = ' ';
                }
            }
            else if(display[i][j] == 'T')
            {

            }
            else if(display[i][j] == '7')
            {
                if((display[i+1][j] == ' ') && (display[i+2][j] != '^'))
                {
                    display[i][j] = '*';
                    display[i+1][j] = '*';
                }
                else if(i == r-2)
                {
                    display[i][j] = '*';
                }
                else if(display[i+1][j] == '*')
                {
                    display[i][j] = '*';
                    display[i+1][j] = '7';
                }
                else if((display[i+1][j] == '^') && (display[i+2][j] == ' '))
                {
                    display[i][j] = '*';
                    display[i+1][j] = ' ';
                }
                else if(display[i+1][j] == '9')
                {
                    if(display[0][0] == '9')
                    {
                        display[0][0] = '_';
                        display[i][j] = '*';
                        display[i+1][j] = '^';
                    }
                    else
                    {
                        display[i][j] = '*';
                        display[i+1][j] = ' ';
                    }
                }
                else if((display[i+1][j] == ' ') && (display[i+2][j] == '^'))
                {
                    display[i][j] = '*';
                    display[i+2][j] = ' ';
                }
                else if((display[i+1][j] == '^') && (display[i+2][j] == '^'))
                {
                    display[i][j] = '*';
                    display[i+1][j] = '^';
                    display[i+2][j] = ' ';
                }
                else if((display[i+1][j] == '^') && (display[i+2][j] == '9'))
                {

                    if(display[0][0] == '9')
                    {
                        display[i][j] = '*';
                        display[i+1][j] = '^';
                        display[i+2][j] = '^';
                        display[0][0] = '_';
                    }
                    else
                    {
                        display[i][j] = '*';
                        display[i+1][j] = ' ';
                        display[i+2][j] = '^';
                    }
                }
            }
            else if(display[i][j] == '9')
            {
                if(display[0][0] == '9')
                {
                    display[i-1][j] = '^';
                    display[i][j] = '^';
                    display[0][0] = '_';
                }
                else
                {
                    display[i][j] = '^';
                }
            }
        }
    }
    return;
}
void printout(char display[][smallcolumn],int r, int& o)
{
    for(int i = 0; i < 12; i++)
    {
        for(int j = 0; j < 23; j++)
        {
            switch (display[i][j])
            {
                case 'U':
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
                    cout << display[i][j];
                    break;
                case 'n':
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);
                    cout << display[i][j];
                    break;
                case 'T':
                    if(o == 1)
                    {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
                        cout << display[i][j];
                    }
                    else if(o ==2)
                    {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
                        cout << display[i][j];
                    }
                    else
                    {
                        return;
                    }
                    break;
                case '|':
                case '_':
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
                    cout << display[i][j];
                    break;
                case '^':
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
                    cout << display[i][j];
                    break;
                case '*':
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
                    cout << display[i][j];
                    break;
                case ' ':
                    cout << display[i][j];
                    break;
                default:
                    cout << display[i][j];
                    break;
            }
            cout << " ";
        }
        cout << endl;
    }
    return;
}
void bomb(char display[][smallcolumn],int r)
{
    int p = 0,ur = 1;
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < smallcolumn; j++)
        {
            if(display[i][j] == 'U' || display[i][j] == 'n')
            {
                ur = i;
                break;
            }
        }
    }

    for(int i = 1; i < (smallcolumn-1); i++)
    {
        if((display[ur][i] == 'U') || (display[ur][i] == 'n'))
        {
            p++;
        }
    }

    srand(time(0));
    int a = (rand() % p) + 1;

    for(int i = 1, t = 0; i < (smallcolumn-1); i++)
    {
        if((display[ur][i] == 'U') || (display[ur][i] == 'n'))
        {
            t++;
        }
        if(t == a)
        {
            int w;
            for(w = ur; ((display[w][i] == 'U') && (display[w][i] == 'n')); w++);
            if(display[w+1][i] == '^')
            {
                display[w+1][i] = ' ';
            }
            else
            {
               display[w+1][i] = '*';
            }
            break;
        }

    }
}

void enemy_moves(char display[][smallcolumn],int r, char &wall)
{
    for(int i = 1; i < (r-1); i++)
    {
        if((display[i][smallcolumn-2] == 'U') || (display[i][smallcolumn-2] == 'n'))
        {
            wall = 'r';
        }
        else if((display[i][1] == 'U') || (display[i][1] == 'n'))
        {
            wall = 'l';
        }
    }

    if(wall == 'l')
    {
        for(int i = 1; i < (r-1); i++)
        {
            for(int j = (smallcolumn-2); j > 0; j--)
            {
                if(display[i][j] == 'U')
                {
                    if(display[i][j+1] == '^')
                    {
                        display[i][j+1] = ' ';
                        display[i][j] = ' ';
                    }
                    else
                    {
                        display[i][j+1] = 'U';
                        display[i][j] = ' ';
                    }
                }
                else if(display[i][j] == 'n')
                {
                    if(display[i][j+1] == '^')
                    {
                        display[i][j+1] = ' ';
                        display[i][j] = ' ';
                    }
                    else
                    {
                        display[i][j+1] = 'n';
                        display[i][j] = ' ';
                    }
                }
            }
        }
    }
    else
    {
        for(int i = 1; i < (r-1); i++)
        {
            for(int j = 1; j < (smallcolumn-1); j++)
            {
                if(display[i][j] == 'U')
                {
                    if(display[i][j-1] == '^')
                    {
                        display[i][j-1] = ' ';
                        display[i][j] = ' ';
                    }
                    else
                    {
                        display[i][j-1] = 'U';
                        display[i][j] = ' ';
                    }
                }
                if(display[i][j] == 'n')
                {
                    if(display[i][j-1] == '^')
                    {
                        display[i][j-1] = ' ';
                        display[i][j] = ' ';
                    }
                    else
                    {
                        display[i][j-1] = 'n';
                        display[i][j] = ' ';
                    }
                }
            }
        }
    }
}
void enemy_move_downward(char display[][smallcolumn],int r,int e,int &o)
{
    for(int i = r-4; i > 0; i--)
    {
        for(int j = 1; j < smallcolumn-1; j++)
        {
            if((display[i][j] == 'U') || (display[i][j] == 'n'))
            {
                if(display[i+1][j] == ' ')
                {

                    display[i+1][j] = display[i][j];
                    display[i][j] = ' ';
                }
                else if((display[i+1][j] == '*') && (display[i+2][j] == ' '))
                {
                    display[i+2][j] = display[i+1][j];
                    display[i+1][j] = display[i][j];
                    display[i][j] = ' ';
                }
                else if((display[i+1][j] == '*') && (display[i+2][j] == '^'))
                {
                    display[i+2][j] = ' ';
                    display[i+1][j] = display[i][j];
                    display[i][j] = ' ';
                }
                else if(display[i+1][j] == '^')
                {
                    display[i+1][j] = ' ';
                    display[i][j] = ' ';
                }
                else if((display[i+1][j] == '*') && (display[i+2][j] == '*'))
                {
                    int z = 2,f = 0;
                    for(f = i+3; display[f][j] == '*'; f++,z++);
                    if(display[f][j] == ' ')
                    {
                        for(int v = f-1; v >= i; v--)
                        {
                            display[v+1][j] = display[v][j];
                        }
                        display[i][j] = ' ';
                    }
                    else if(display[f][j] == '^')
                    {
                        display[f][j] = ' ';
                        for(int v = f-2; v >= i; v--)
                        {
                            display[v+1][j] = display[v][j];
                        }
                        display[i][j] = ' ';
                    }
                    else if(display[f][j] == 'T')
                    {
                        o--;
                        if(o == 0)
                            return;
                        for(int v = f-2; v >= i; v--)
                        {
                            display[v+1][j] = display[v][j];
                        }
                        display[i][j] = ' ';
                    }
                }
            }
        }
    }
    return;
}
int count_U(char display[][smallcolumn],int r)
{
    int p = 0;
    for(int i = 1; i < r-1; i++)
    {
        for(int j = 1; j < (smallcolumn-1); j++)
        {
            if((display[i][j] == 'U') || (display[i][j] == 'n'))
            {
                p++;
            }
        }
    }

    return p;
}

void check_U_move_downward_or_not(int &iwin, int &p, char display[][smallcolumn], int r, int e ,int &o)
{
    if(((iwin % 5) == 3) && (p == 1) && (iwin != 28))
        p = 2;//not move yet
    else if(((iwin % 5) == 3) && (p == 3))
        p = 3;
    else
        p = 1;

    if(p == 2)
    {
        enemy_move_downward(display,r, e,o);
        p = 3;//moved
    }
    return;
}

int easysmall(int e, int& o)
{
    char display[smallrow][smallcolumn];
    for(int i = 0; i < smallrow; i++)
    {
        for(int j = 0; j < smallcolumn; j++)
        {
            display[i][j] = ' ';
        }
    }
    game_screen(display,smallrow,o);
    while(o != 0)
    {
        press(display,smallrow,e,o);
        if(o == 0)
            break;
        search_n_move(display,smallrow,e,o);
        if(o == 0)
            break;
        int iwin = count_U(display,smallrow);
        if(iwin == 0)
            break;
        gotoxy(0,0);
        printout(display, smallrow,o);
        Sleep(500);

        press(display,smallrow,e,o);
        if(o == 0)
            break;
        search_n_move(display,smallrow,e,o);
        if(o == 0)
            break;
        iwin = count_U(display,smallrow);
        if(iwin == 0)
             break;
        bomb(display,smallrow);
        gotoxy(0,0);
        printout(display, smallrow,o);
        Sleep(500);

        press(display,smallrow,e,o);
        if(o == 0)
            break;
        search_n_move(display,smallrow,e,o);
        if(o == 0)
            break;
        iwin = count_U(display,smallrow);
        if(iwin == 0)
            break;
        gotoxy(0,0);
        printout(display, smallrow,o);
        Sleep(500);

        enemy_moves(display, smallrow,wall);
        iwin = count_U(display,smallrow);
        if(iwin == 0)
            break;
        press(display,smallrow,e,o);
        if(o == 0)
            break;
        search_n_move(display,smallrow,e,o);
        if(o == 0)
            break;
        iwin = count_U(display,smallrow);
        if(iwin == 0)
            break;
        bomb(display,smallrow);
        gotoxy(0,0);
        printout(display, smallrow,o);
        Sleep(500);
    }

    if(o != 0)
        return 1;
    else
        return 0;
}
int mediumsmall(int e, int &o)
{
    char display[smallrow][smallcolumn];
    for(int i = 0; i < smallrow; i++)
    {
        for(int j = 0; j < smallcolumn; j++)
        {
            display[i][j] = ' ';
        }
    }
    game_screen(display,smallrow,o);
    while(o != 0)
    {
        press(display,smallrow,e,o);
        if(o == 0)
            break;
        search_n_move(display,smallrow,e,o);
        if(o == 0)
            break;
        int iwin = count_U(display,smallrow);
        if(iwin == 0)
            break;
        gotoxy(0,0);
        printout(display, smallrow,o);
        Sleep(500);

        press(display,smallrow,e,o);
        if(o == 0)
            break;
        search_n_move(display,smallrow,e,o);
        if(o == 0)
            break;
        iwin = count_U(display,smallrow);
        if(iwin == 0)
             break;
        bomb(display,smallrow);
        gotoxy(0,0);
        printout(display, smallrow,o);
        Sleep(500);

        press(display,smallrow,e,o);
        if(o == 0)
            break;
        search_n_move(display,smallrow,e,o);
        if(o == 0)
            break;
        iwin = count_U(display,smallrow);
        if(iwin == 0)
            break;
        gotoxy(0,0);
        printout(display, smallrow,o);
        Sleep(500);

        enemy_moves(display, smallrow,wall);
        iwin = count_U(display,smallrow);
        if(iwin == 0)
            break;
        press(display,smallrow,e,o);
        if(o == 0)
            break;
        search_n_move(display,smallrow,e,o);
        if(o == 0)
            break;
        iwin = count_U(display,smallrow);
        if(iwin == 0)
            break;
        bomb(display,smallrow);
        gotoxy(0,0);
        printout(display, smallrow,o);
        Sleep(500);
    }

    if(o != 0)
        return 1;
    else
        return 0;
}
int hardsmall(int e, int o, int &p)
{
    char display[smallrow][smallcolumn];
    for(int i = 0; i < smallrow; i++)
    {
        for(int j = 0; j < smallcolumn; j++)
        {
            display[i][j] = ' ';
        }
    }
    game_screen(display,smallrow,o);
    while(o != 0)
    {
        press(display,smallrow,e,o);
        int iwin = count_U(display,smallrow);
        if((o == 0)||(iwin == 0))
            break;
        iwin = count_U(display,smallrow);
        if((o == 0)||(iwin == 0))
            break;
        check_U_move_downward_or_not(iwin,p,display,smallrow,e,o);
        if((o == 0)||(iwin == 0))
            break;
        search_n_move(display,smallrow,e,o);
        if((o == 0)||(iwin == 0))
            break;
        iwin = count_U(display,smallrow);
        check_U_move_downward_or_not(iwin,p,display,smallrow,e,o);
        if((o == 0)||(iwin == 0))
            break;
        gotoxy(0,0);
        printout(display, smallrow,o);
        Sleep(500);

        press(display,smallrow,e,o);
        if((o == 0)||(iwin == 0))
            break;
        iwin = count_U(display,smallrow);
        check_U_move_downward_or_not(iwin,p,display,smallrow,e,o);
        if((o == 0)||(iwin == 0))
            break;
        search_n_move(display,smallrow,e,o);
        if((o == 0)||(iwin == 0))
            break;
        iwin = count_U(display,smallrow);
        check_U_move_downward_or_not(iwin,p,display,smallrow,e,o);
        if((o == 0)||(iwin == 0))
            break;
        bomb(display,smallrow);
        gotoxy(0,0);
        printout(display, smallrow,o);
        Sleep(500);

        press(display,smallrow,e,o);
        if((o == 0)||(iwin == 0))
            break;
        iwin = count_U(display,smallrow);
        check_U_move_downward_or_not(iwin,p,display,smallrow,e,o);
        if((o == 0)||(iwin == 0))
            break;
        search_n_move(display,smallrow,e,o);
        if((o == 0)||(iwin == 0))
            break;
        iwin = count_U(display,smallrow);
        check_U_move_downward_or_not(iwin,p,display,smallrow,e,o);
        if((o == 0)||(iwin == 0))
            break;
        gotoxy(0,0);
        printout(display, smallrow,o);
        Sleep(500);

        enemy_moves(display, smallrow,wall);
        if((o == 0)||(iwin == 0))
            break;
        iwin = count_U(display,smallrow);
        check_U_move_downward_or_not(iwin,p,display,smallrow,e,o);
        if((o == 0)||(iwin == 0))
            break;
        press(display,smallrow,e,o);
        if((o == 0)||(iwin == 0))
            break;
        iwin = count_U(display,smallrow);
        check_U_move_downward_or_not(iwin,p,display,smallrow,e,o);
        if((o == 0)||(iwin == 0))
            break;
        search_n_move(display,smallrow,e,o);
        if((o == 0)||(iwin == 0))
            break;
        iwin = count_U(display,smallrow);
        check_U_move_downward_or_not(iwin,p,display,smallrow,e,o);
        if((o == 0)||(iwin == 0))
            break;
        bomb(display,smallrow);
        gotoxy(0,0);
        printout(display, smallrow,o);
        Sleep(500);
    }
    if(o != 0)
        return 1;
    else
        return 0;
}
