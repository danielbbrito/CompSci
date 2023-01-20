#include <bits/stdc++.h>

using namespace std;

#define SIZE 25

char image[25][25];
int n;

int X[] = {1, -1, 0, 0, 1, -1, 1, -1};
int Y[] = {0, 0, 1, -1, 1, -1, -1, 1};

// Checks if array element is not out of bounds
bool isSafe(int i, int j)
{
    return i >= 0 && j >= 0 && i < n && j < n ? true : false;
}

// Flood fills a war eagle
void FloodFill(int i, int j)
{
    image[i][j] = '0';

    for (int k = 0; k < 8; k++)
    {
        int Ni = i + Y[k];
        int Nj = j + X[k];

        if (isSafe(Ni, Nj) && image[Ni][Nj] == '1')
            FloodFill(Ni, Nj);
    }

    return;
}

int main()
{   
    // Read until EOF
    for (int k = 1; cin >> n; k++)
    {
        int count = 0;

        // Read image grid
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> image[i][j];

        // Iterate over image
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                // Flood fill the war eagle and add one to count
                if (image[i][j] == '1')
                {
                    FloodFill(i, j);
                    count++;
                }

            // Print amount of war eagles
            cout << "Image number " << k << " contains " << count << " war eagles." << endl;
    }

    return 0;
}