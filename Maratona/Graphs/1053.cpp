#include <bits/stdc++.h>

using namespace std;
map<string, set<string> > adjlist;

float

int main()
{
    int t;

    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        int n;
        cin >> n;

        string coord1, coord2;
        for (int j = 0; j < n; j++)
        {
            cin >> coord1 >> coord2;
            adjlist[coord1].insert(coord2);
            adjlist[coord2].insert(coord1);
        }


        cout << "Case " << t << ": " << bfs();
    }
}