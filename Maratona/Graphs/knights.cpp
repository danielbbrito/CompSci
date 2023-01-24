#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> coords;
int Y[] = {-2, -2, 2, 2, -1, 1, -1, 1};
int X[] = {-1, 1, -1, 1, 2, 2, -2, -2};

bool isValid(int i, int j)
{
    return i >= 0 && j >= 0 && i < 8 && j < 8;
}

int bfs()
{
    vector<vector<int>> dist(8, vector<int>(8, -1));
    queue<pair<int, int>> q;
    dist[coords[0].first][coords[0].second] = 0;
    q.push(coords[0]);

    while (q.size())
    {
        pair<int, int> curr = q.front();
        q.pop();

        if (curr == coords[1])
            return dist[curr.first][curr.second];
        
        for (int i = 0; i < 8; i++)
        {
            int Ni = curr.first + Y[i];
            int Nj = curr.second + X[i];

            if (isValid(Ni, Nj) && dist[Ni][Nj] == -1)
            {
                dist[Ni][Nj] = dist[curr.first][curr.second] + 1;
                q.push({Ni, Nj});
            }
        }
    }
    
    return -1;
}

int main()
{
    string coord1, coord2;

    while (cin >> coord1 >> coord2)
    {
        coords.push_back({(int)(coord1[0] - 96), (int)(coord1[1] - 48)});
        coords.push_back({(int)(coord2[0] - 96), (int)(coord2[1] - 48)});

        cout << "To get from " << coord1 << " to " << coord2 << " takes " << bfs() << " knight moves.\n";

        coords.clear();
    }
}