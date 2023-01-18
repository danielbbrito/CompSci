#include <bits/stdc++.h>

using namespace std;

char sky[101][101];
int r, c;
int X[] = {1, -1, 0, 0, 1, -1, 1, -1};
int Y[] = {0, 0, 1, -1, 1, -1, -1, 1};

// Validates if an element exists
bool isValid(int i, int j)
{
    return i >= 0 && j >= 0 && i < r && j < c ? true : false;
}

// Floods objects that are not stars
void floodFill(int i, int j)
{
    sky[i][j] = '.';

    for (int k = 0; k < 8; k++)
    {
        int Ni = i + Y[k];
        int Nj = j + X[k];

        if (isValid(Ni, Nj) && sky[Ni][Nj] == '*')
            floodFill(Ni, Nj);
    }

    return;
}

// Checks whether element is a star or not
bool countingStars(int i, int j)
{
    for (int k = 0; k < 8; k++)
    {
        int Ni = i + Y[k];
        int Nj = j + X[k];

        if (isValid(Ni, Nj) && sky[Ni][Nj] == '*')
            return false;
    }

    return true;
}

int main()
{
    // Read size of first map
    cin >> r >> c;

    while (r != 0 && c != 0)
    {
        int ans = 0;
        
        // Read map
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                cin >> sky[i][j];
        
        // Iterate over map
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                if (sky[i][j] == '*')
                {   // If pixel is a star, add one to ans
                    if (countingStars(i, j))
                        ans++;

                    // If pixel is not a star, fill all adjacent pixels so that they are not checked
                    else
                        floodFill(i, j);
                }
        // Print number of stars
        cout << ans << endl;

        // Read a new map size
        cin >> r >> c;
    }

    return 0;
}