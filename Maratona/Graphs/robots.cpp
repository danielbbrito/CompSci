#include <bits/stdc++.h>

using namespace std;

char grid[100][100];
int currentRow;
int currentCol;
int currentDir;
int n, m, s;

int Y[] = {-1, 0, 1, 0};
int X[] = {0, 1, 0, -1};

// Checks wheter robot can be moved to cell
bool isValid(int i, int j)
{
    return i >= 0 && j >= 0 && i < n && j < m && grid[i][j] != '#';
}

// Moves robot
void moveRobot(int i, int j)
{
    int newRow = currentRow + Y[currentDir];
    int newCol = currentCol + X[currentDir];

    if (isValid(newRow, newCol))
    {
        currentRow = newRow;
        currentCol = newCol;
        return;
    }
}

// Changes robot direction
void changeDirection(char d)
{
    if (d == 'E')
        currentDir = (currentDir - 1) % 4;

    else
        currentDir = (currentDir + 1) % 4;

    if (currentDir < 0)
        currentDir += 4;
}

int main()
{
    map<char, int> dir;

    dir['N'] = 0;
    dir['L'] = 1;
    dir['S'] = 2;
    dir['O'] = 3;

    cin >> n >> m >> s;

    // Read until not valid
    while (n != 0 && m != 0 && s != 0)
    {
        int count = 0;

        // Read grid
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];

                // Find inital position and direction
                if (dir.find(grid[i][j]) != dir.end())
                {
                    currentRow = i;
                    currentCol = j;
                    currentDir = dir[grid[i][j]];
                }
            }
        cin.ignore();

        // Read instructions
        string commands;
        getline(cin, commands);

        // Iterate through commands
        for (int i = 0; i < s; i++)
        {
            if (commands[i] == 'F')
            {
                // Move robot, if possible
                moveRobot(currentRow, currentCol);

                if (grid[currentRow][currentCol] == '*')
                {
                    count++;
                    grid[currentRow][currentCol] = '.';
                }
            }

            else if (commands[i] == 'D' || commands[i] == 'E')
            {
                // Change direction
                changeDirection(commands[i]);
            }
        }

        cout << count << endl;
        cin >> n >> m >> s;
    }
}