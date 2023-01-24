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
            if (curr + it <= 9999 && dist[curr + it] == TAM)
            {
                int v = curr + it;
                dist[v] = dist[curr] + 1;
                q.push(v);
            }

            if (curr + it > 9999 && dist[curr + it] == TAM)
            {
                int v = (curr + it) - 9999;
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

    while (l != 0 || u != 0 || r != 0)
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