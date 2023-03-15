#include <bits/stdc++.h>

using namespace std;
vector<int> adjlist[2500];
int day, ct;

void bfs(int s)
{
    bool visited[2500];
    queue<int>
}

int main()
{
    int e;

    cin >> e;

    for (int i = 0; i < e; i++)
    {
        int n;
        cin >> n;

        while (n--)
        {
            int f;
            cin >> f;
            adjlist[i].push_back(f);
            adjlist[f].push_back(i);
        }
    }

    int t;
    cin >> t;

    while (t--)
    {
        ct = 0;
        day = 0;
        // Check each test case
        int c;
        cin >> c;
        bfs(c);
    }
}