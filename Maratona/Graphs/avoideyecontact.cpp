#include <bits/stdc++.h>

using namespace std;

int h,w;
char grid[2005][2005];

void clear(int i, int j)
{
    if (grid[i][j] == '^')
    {
        int ni = i - 1;
        grid[i][j] = '#';
        while (grid[ni][j] == '.')
        {
            grid[ni][j] = '#';
            ni--;
        }
    }

    if (grid[i][j] == 'v')
    {
        int ni = i + 1;
        grid[i][j] = '#';
        while (grid[ni][j] == '.')
        {
            grid[ni][j] = '#';
            ni++;
        }
    }

    if (grid[i][j] == '>')
    {
        int nj = j + 1;
        grid[i][j] = '#';
        while (grid[i][nj] == '.')
        {
            grid[i][nj] = '#';
            j++;
        }
    }

    if (grid[i][j] == '<')
    {
        int nj = j - 1;
        grid[i][j] = '#';
        while (grid[i][nj] == '.')
        {
            grid[i][nj] = '#';
            j--;
        }
    }
}

bool isSafe(int i, int j)
{
    return i >= 0 && j >= 0 && i < h && j < w;
}

int bfs(pair<int,int> s, pair<int, int> e)
{
    map<pair<int,int>, int> dist;
    queue<pair<int,int>> q;
    int y[] = {1, 0, -1, 0};
    int x[] = {0, 1, 0, -1};
    q.push(s);
    dist[s] = 0;

    while (q.size())
    {
        pair<int, int> curr = q.front();q.pop();

        if (curr == e) return dist[e];

        for (int i = 0; i < 4; i++)
        {
            int ni = curr.first + y[i], nj = curr.second + x[i];

            if (isSafe(ni, nj) && grid[ni][nj] == '.' && (dist.find({ni, nj}) == dist.end() || dist[{ni, nj}] > dist[curr] + 1))
            {
                q.push({ni, nj});
                dist[{ni, nj}] = dist[curr] + 1;
            }
        } 
    }

    return -1;
}

int main()
{
    cin >> h >> w;
    pair<int,int> s, e;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < h; j++)
            cin >> grid[i][j];


    // Clear lines of sight
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (grid[i][j] == 'S')
            {
                s = {i, j};
            }

            else if (grid[i][j] == 'G')
            {
                e = {i, j};
            }

            else if (grid[i][j] != '.' && grid[i][j] != '#')
            {
                clear(i, j);
            }
        }
    }
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
            cout << grid[i][j];
        
        cout << endl;
    }
    // Run bfs
    int ans = bfs(s, e);
    
    cout << ans << endl;
}