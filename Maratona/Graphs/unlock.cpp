#include <bits/stdc++.h>

using namespace std;
#define TAM -1
vector<int> buttons;

string bfs(int s, int e)
{
    vector<int> dist(10000, TAM);
    queue<int> q;

    dist[s] = 0;
    q.push(s);

    while (q.size())
    {
        int curr = q.front();
        q.pop();

        if (curr == e)
            return to_string(dist[e]);
        

        for (auto it: buttons)
        {
            if (dist[(curr + it) % 10000] == TAM)
            {
                int v = curr + it;
                v = v % 10000;
                dist[v] = dist[curr] + 1;
                q.push(v);
            }
        }

    }

    return "Permanently Locked";
}

int main()
{
    // While not 0
    int l, u, r, c=1;
    cin >> l >> u >> r;

    while (l || u || r)
    {
        // Read buttons available
        for (int i = 0; i < r; i++)
        {
            int b;
            cin >> b;
            buttons.push_back(b);
        }

        cout << "Case "<< c << ": " << bfs(l, u) << endl;

        c++;
        buttons.clear();

        cin >> l >> u >> r;
    }
}