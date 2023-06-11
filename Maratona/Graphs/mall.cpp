#include <bits/stdc++.h>
using namespace std;
int adjlist[2001][2001];

int main()
{
    int p;
    cin >> p;

    while (p)
    {
        int m = max(0, p);

        for (int i = 0; i < 2001; i++)
            memset(adjm[i], 0, sizeof(adjm[i]));

        while (p--)
        {
            int a, b;
            cin >> a >> b;
            adjm[a][b] = 1;
            adjm[b][a] = 1;
        }

        cin >> p;
        
        m = max(m, p);

        while (p--)
        {
            int a, b;
            cin >> a >> b;
            adjm[a][b] = 1;
            adjm[b][a] = 1;
        }

        for (int i = 0; i <= p; i++)
        {
            
        }
    }
}