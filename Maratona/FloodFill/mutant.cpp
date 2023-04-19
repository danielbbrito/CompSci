#include <bits/stdc++.h>

using namespace std;
map<char, int> dirs = {
    {'N', 0},
    {'E', 1},
    {'S', 2},
    {'W', 3}
};

map<int, char> dirs2 = {
    {0, 'N'},
    {1, 'E'},
    {2, 'S'},
    {3, 'W'}
};

bool fell[50][50];
int maxI, maxJ, currI, currJ;
char currDir;
int intDir;
int Y[] = {-1, 0, 1, 0};
int X[] = {0, 1, 0, -1};

bool isSafe(int i, int j)
{
    return i >= 0 && j >= 0 && i <= maxI && j <= maxJ;
}

void changeDir(char command)
{
    intDir = dirs[currDir];
    if (command == 'L')
        intDir = (intDir - 1) % 4;
    
    else
        intDir = (intDir + 1) % 4;
    
    if (intDir < 0)
        intDir += 4;

    currDir = dirs2[intDir];
    return;
}

bool moveBot()
{
    int newI = currI + Y[dirs[currDir]];
    int newJ = currJ + X[dirs[currDir]];

    // If a robot has already fallen from there, do nothing
    if (fell[newI][newJ])
        return true;

    currI = newI;
    currJ = newJ;

    // Check if robot will fall
    if (isSafe(newI, newJ))
        return true;
    
    else
    {
        fell[currI][currJ] = true;
        return false;
    }
}

int main()
{
    cin >> maxI >> maxJ;

    while (cin >> currI >> currJ >> currDir)
    {
        string commands;
        cin >> commands;

        for (int i = 0; i < commands.size(); i++)
        {
            if (commands[i] == 'L' || commands[i] == 'R')
                changeDir(commands[i]);
            else
            {
                if (!moveBot())
                {
                    cout << currI << ' ' << currJ << ' ' << currDir << " LOST\n";
                    break;
                }
            }
        }

        cout << currI << ' ' << currJ << ' ' << currDir << endl;
    }

    return 0;
}