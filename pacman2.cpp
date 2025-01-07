#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
using namespace std;

void maze();
void read();
void xycord(int x, int y);
char getCharAtxy(short int x, short int y);
void erasepm(int x, int y);
void printpm(int x, int y);
void printg(int x, int y);
void printScore(int score, int lives, int high);
void gameoover();
fstream score_data;
int x = 5, y = 5;
int gx[5] = {2, 2, 45, 96, 28};
int gy[5] = {2, 24, 3, 2, 9};
int large = 0;
int high = 0;
int score = 0;
int lives = 3;
bool g[5] = {true, true, true, true, true};
bool gameover = true;

int main()
{
    system("Color 0A");
    read();
    maze();
    printScore(score, lives, high);
    while (gameover)
    {
        xycord(x, y);

        if (GetAsyncKeyState(VK_UP))
        {
            char next = getCharAtxy(x, y - 1);
            if (next == ' ' || next == '.' || next == '$')
            {

                erasepm(x, y);
                y = y - 1;
                printpm(x, y);
                if (next == '.')
                {
                    score++;
                }
                if (next == '$')
                {
                    lives++;
                }
                printScore(score, lives, high);
            }
        }
        if (GetAsyncKeyState(VK_DOWN))
        {
            char next = getCharAtxy(x, y + 1);

            if (next == ' ' || next == '.' || next == '$')
            {
                erasepm(x, y);
                y = y + 1;
                printpm(x, y);
                if (next == '.')
                {
                    score++;
                }
                if (next == '$')
                {
                    lives++;
                }
                printScore(score, lives, high);
            }
        }
        if (GetAsyncKeyState(VK_LEFT))
        {
            char next = getCharAtxy(x - 1, y);

            if (next == ' ' || next == '.' || next == '$')
            {
                erasepm(x, y);
                x = x - 1;
                printpm(x, y);
                if (next == '.')
                {
                    score++;
                }
                if (next == '$')
                {
                    lives++;
                }
                printScore(score, lives, high);
            }
        }
        if (GetAsyncKeyState(VK_RIGHT))
        {
            char next = getCharAtxy(x + 1, y);

            if (next == ' ' || next == '.' || next == '$')
            {
                erasepm(x, y);
                x = x + 1;
                printpm(x, y);
                if (next == '.')
                {
                    score++;
                }
                if (next == '$')
                {
                    lives++;
                }
                printScore(score, lives, high);
            }
        }
        if (score > large)
        {
            large = score;
        }
        else if (large > high)
        {
            high = large;
            printScore(score, lives, high);
        }
        // Ghost 1
        erasepm(gx[0], gy[0]);
        if (g[0])
        {
            if (getCharAtxy(gx[0] + 1, gy[0]) == '.')
            {
                xycord(gx[0], gy[0]);
                cout << ".";
            }
            gx[0]++;
            if (gx[0] > 96)
            {
                g[0] = false;
            }
        }
        else
        {
            if (getCharAtxy(gx[0] - 1, gy[0]) == '.')
            {
                xycord(gx[0], gy[0]);
                cout << ".";
            }
            gx[0]--;
            if (gx[0] < 3)
            {
                g[0] = true;
            }
        }
        printg(gx[0], gy[0]);
        // ghost 2
        erasepm(gx[1], gy[1]);
        if (g[1])
        {
            if (getCharAtxy(gx[1] + 1, gy[1]) == '.')
            {
                xycord(gx[1], gy[1]);
                cout << ".";
            }
            gx[1]++;
            if (gx[1] > 37)
            {
                g[1] = false;
            }
        }
        else
        {
            if (getCharAtxy(gx[1] - 1, gy[1]) == '.')
            {
                xycord(gx[1], gy[1]);
                cout << ".";
            }
            gx[1]--;
            if (gx[1] < 3)
            {
                g[1] = true;
            }
        }
        printg(gx[1], gy[1]);
        // ghost 3
        erasepm(gx[2], gy[2]);
        if (g[2])
        {
            if (getCharAtxy(gx[2], gy[2] + 1) == '.')
            {
                xycord(gx[2], gy[2]);
                cout << ".";
            }
            gy[2]++;
            if (gy[2] > 18)
            {
                g[2] = false;
            }
        }
        else
        {
            if (getCharAtxy(gx[2], gy[2] - 1) == '.')
            {
                xycord(gx[2], gy[2]);
                cout << ".";
            }
            gy[2]--;
            if (gy[2] < 3)
            {
                g[2] = true;
            }
        }
        printg(gx[2], gy[2]);
        // ghost 4
        erasepm(gx[3], gy[3]);
        if (g[3])
        {
            if (getCharAtxy(gx[3], gy[3] + 1) == '.')
            {
                xycord(gx[3], gy[3]);
                cout << ".";
            }
            gy[3]++;
            if (gy[3] > 23)
            {
                g[3] = false;
            }
        }
        else
        {
            if (getCharAtxy(gx[3], gy[3] - 1) == '.')
            {
                xycord(gx[3], gy[3]);
                cout << ".";
            }
            gy[3]--;
            if (gy[3] < 3)
            {
                g[3] = true;
            }
        }
        printg(gx[3], gy[3]);
        // ghost 5
        erasepm(gx[4], gy[4]);
        if (g[4])
        {
            if (getCharAtxy(gx[4] + 1, gy[4]) == '.')
            {
                xycord(gx[4], gy[4]);
                cout << ".";
            }
            gx[4]++;
            if (gx[4] > 89)
            {
                g[4] = false;
            }
        }
        else
        {
            if (getCharAtxy(gx[4] - 1, gy[4]) == '.')
            {
                xycord(gx[4], gy[4]);
                cout << ".";
            }
            gx[4]--;
            if (gx[4] < 27)
            {
                g[4] = true;
            }
        }
        printg(gx[4], gy[4]);

        for (int i = 0; i < 5; i++)
        {
            if (x == gx[i] && y == gy[i])
            {
                lives--;
                printScore(score, lives, high);
                if (lives == 0)
                {
                    high = score;
                    score_data.open("Scoring File.txt", ios ::out);
                    score_data << high;
                    score_data.close();
                    gameover = false;
                    system("cls");
                    xycord(0, 0);
                    gameoover();
                    
                }
                else
                {

                    x = 5;
                    y = 5;
                    printpm(x, y);
                }
            }
        }
        if (score > 1561)
        {
            gameover = false;
            xycord(0, 27);
            cout << "YOU WON THE GAME.";
        }

        Sleep(70);
    }
}

void maze()
{

    cout << "####################################################################################################" << endl;
    cout << "##................................................................................................##" << endl;
    cout << "##.......%%%%%%%%%%%%...$...%%%%%%%%%%%%.......%%%%%%%%%%%%.......%%%%%%%%%%%%%......%%...........##" << endl;
    cout << "##.......%%........%%.......%%        %%.......%%        %%.......%%         %%......%%...........##" << endl;
    cout << "##.......%%........%%.......%%        %%.......%%        %%.......%%%%%%%%%%%%%......%%%%%%%......##" << endl;
    cout << "##.......%%........%%.......%%        %%.......%%        %%.......%%.....%%...............%%......##" << endl;
    cout << "##.......%%........%%.......%%        %%.......%%        %%....$..%%.......%%.....................##" << endl;
    cout << "##.......%%........%%.......%%%%%%%%%%%%.......%%%%%%%%%%%%.......%%.........%%   %%%%%%%%%%%.....##" << endl;
    cout << "##......................%%.................................................................%%.....##" << endl;
    cout << "##...%%........%%.......%%....%%%%%%%%%............%%%%%%%%%%%........%%.....%%%%%%%%%%....%%.....##" << endl;
    cout << "##...%%........%%.......%%...........%%....%%......%%.................%%.....%%............%%.....##" << endl;
    cout << "##...%%........%%....................%%....%%......%%....%%...%%%%%%%%%%%%...%%...%%%%%%%%%%%.....##" << endl;
    cout << "##...%%........%%%%%%%%%% .$.........%%....%%......%%....%%.........%%.......%%...................##" << endl;
    cout << "##...%%....................................%%......%%....%%...%%....%%.................%%.........##" << endl;
    cout << "##...%%......................%%%%%%%%%%%%%%%%............%%...%%....%%.....%%..........%%.........##" << endl;
    cout << "##...%%.........%%%%%%%%%.......................%%%%%%%%%%%...%%....%%.....%%..........%%.........##" << endl;
    cout << "##...%%.........%%.....%%.....................................%%...........%%....%%%%%%%%%%%%%%...##" << endl;
    cout << "##...%%%%.......%%.....%%.......%%%%%%%%%%.......%%%%%%%%%%%%%%%%%%........%%..........%%.........##" << endl;
    cout << "##..............%%.....%%.......%%.......................%%................%%..........%%.........##" << endl;
    cout << "##.......%%.....%%.....%%.......%%........%%%%%%%%%%%....%%........%%%%%%%%%%....%%....%%.........##" << endl;
    cout << "##.......%%............%%.......%%.................%%....%%............%%........%%...............##" << endl;
    cout << "##.......%%............%%%%%%%%%%%.....%%..........%%....%%............%%........%%..........$....##" << endl;
    cout << "##....%%%%%%%%%%%%%%.....$.............%%..........%%..................%%........%%%%%%%%%%.......##" << endl;
    cout << "##.....................................%%.........................................................##" << endl;
    cout << "####################################################################################################" << endl;
}
void xycord(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
char getCharAtxy(short int x, short int y)
{
    CHAR_INFO ci;
    COORD xy = {0, 0};
    SMALL_RECT rect = {x, y, x, y};
    COORD coordBufsize = {1, 1};
    // coordBufsize.X=1;
    // coordBufsize.Y=1;
    return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufsize, xy, &rect) ? ci.Char.AsciiChar : '\0';
}
void erasepm(int x, int y)
{
    xycord(x, y);
    cout << " ";
}

void printpm(int x, int y)
{
    xycord(x, y);
    cout << "p";
}
void printScore(int score, int lives, int high)
{
    xycord(0, 26);
    cout << "Score: " << score << "  ";
    xycord(12, 26);
    cout << "LIVES: " << lives << "  ";
    xycord(26, 26);
    cout << "HIGH SCORE:" << high << "   ";
}
void printg(int x, int y)
{
    xycord(x, y);
    cout << "g";
}

void read()
{
    score_data.open("Scoring File.txt", ios ::in);
    score_data >> high;
    score_data.close();
}
void gameoover()
{
cout<<"_____________________________________________________________________________________________________"<<endl;
cout<<" $$$$$$\\   $$$$$$\\  $$\\      $$\\ $$$$$$$$\\        $$$$$$\\  $$\\    $$\\ $$$$$$$$\\ $$$$$$$\\  "<<endl;
cout<<"$$  __$$\\ $$  __$$\\ $$$\\    $$$ |$$  _____|      $$  __$$\\ $$ |   $$ |$$  _____|$$  __$$\\ "<<endl;
cout<<"$$ /  \\__|$$ /  $$ |$$$$\\  $$$$ |$$ |            $$ /  $$ |$$ |   $$ |$$ |      $$ |  $$ |"<<endl;
cout<<"$$ |$$$$\\ $$$$$$$$ |$$\\$$\\$$ $$ |$$$$$\\          $$ |  $$ |\\$$\\  $$  |$$$$$\\    $$$$$$$  |"<<endl;
cout<<"$$ |\\_$$ |$$  __$$ |$$ \\$$$  $$ |$$  __|         $$ |  $$ | \\$$\\$$  / $$  __|   $$  __$$< "<<endl;
cout<<"$$ |  $$ |$$ |  $$ |$$ |\\$  /$$ |$$ |            $$ |  $$ |  \\$$$  /  $$ |      $$ |  $$ |"<<endl;
cout<<"\\$$$$$$  |$$ |  $$ |$$ | \\_/ $$ |$$$$$$$$\\        $$$$$$  |   \\$  /   $$$$$$$$\\ $$ |  $$ |"<<endl;
cout<<" \\______/ \\__|  \\__|\\__|     \\__|\\________|       \\______/     \\_/    \\________|\\__|  \\__|"<<endl;
cout<<"______________________________________________________________________________________________________"<<endl;                                                                                          
                                                                                          
                                                                                          

}