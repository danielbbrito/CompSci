#include <iostream>

using namespace std;

char wall, maze[35][85];

int n, m, c, r=0;
int X[] = {1, -1, 0, 0};
int Y[] = {0, 0, 1, -1};

bool isValid(int i, int j)
{
    return i >= 0 && j >= 0 && i < r && j < c;
}

void FloodFill(int i, int j)
{
    maze[i][j] = '#';

    for (int k = 0; k < 4; k++)
    {
        int Ni = i + Y[k];
        int Nj = j + X[k];

        if (isValid(Ni, Nj) && maze[Ni][Nj] == ' ')
            FloodFill(Ni, Nj);
    }

    return;
}

int main()
{
    int t;

    // Read number of test cases
    cin >> t;
    cin.ignore();

    while (t--)
    {
        memset(maze, '\0', sizeof(maze));
        string line;
        char wall;
        int startRow;
        int startCol;

        // Read maze
        r = 0;
        do
        {
            getline(cin, line);

            int len = line.length();

            int i;
            for (i = 0; i < len; i++)
            {
                maze[r][i] = line[i];

                if (line[i] == '*')
                {
                    startRow = r;
                    startCol = i;
                }
            }
            
            if (r == 0)
                c = i;
            
            r++;
        }
        while (line[0] != '_');

        FloodFill(startRow, startCol);

        // Print painted maze
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
                cout << maze[i][j];
            
            cout << endl;
        }
            
    }

    return 0;
}