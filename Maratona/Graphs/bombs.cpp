#include <bits/stdc++.h>
using namespace std;

int Y[] = {1, -1, 0, 0};
int X[] = {0, 0, 1, -1};

int bfs(pair<int, int> s, pair<int, int> e, bool b[][1001])
{
    vector<vector<int>> dist(1000, vector<int>(1000, -1));
    queue<pair<int, int>> q;

    dist[s.first][s.second] = 0;
    q.push(s);

    while (q.size())
    {
        pair<int, int> curr = q.front();
        q.pop();

        if (curr == e)
            return dist[curr.first][curr.second];

        for (int i = 0; i < 4; i++)
        {
            int Ni = curr.first + Y[i];
            int Nj = curr.second + X[i];

            if (Ni >=0 && Nj >= 0 && Ni <= e.first && Nj <= e.second && dist[Ni][Nj] == -1 && !b[Ni][Nj])
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
    int r, c;

    cin >> r >> c;

    // While valid
    while (r != 0 || c != 0)
    {
        bool bombs[1001][1001] = {false};

        // Read amount of bombs
        int t;
        cin >> t;

        // Read info about the bombs
        for (int i = 0; i < t; i++)
        {
            int row, amount, col;
            cin >> row >> amount;

            while (amount--)
            {
                cin >> col;

                // If there is a bomb set location to true
                bombs[row][col] = true;
            }
        }

        // Read coordinates
        pair<int, int> start;
        pair<int, int> end;

        int i, j;
        cin >> i >> j;
        start = make_pair(i, j);
        cin >> i >> j;
        end = make_pair(i, j);

        // Find shortest path
        cout << bfs(start, end, bombs) << endl;

        // Start new test case
        cin >> r >> c;
    }

    return 0;
}