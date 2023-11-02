#include <bits/stdc++.h>

using namespace std;

map<string, set<string>> adj, adjt;
map<string, bool> seen;
vector<string> order, circle;

void kosaraju(string s, int pass) // Pass indicates wether we are working with the original or transpose graph
{
    seen[s] = true;

    set<string> &neighbors = pass == 1 ? adj[s] : adjt[s];

    for (auto it: neighbors)
        if(!seen[it])
            kosaraju(it, pass);
    
    if (pass == 1)
        order.push_back(s);
    else
        circle.push_back(s);
}
int main()
{
    int n, m, t = 1;
    cin >> n >> m;

    while (n || m)
    {
        cout << "Calling circles for data set " << t << ":\n";

        while (m--)
        {
            string a, b;cin >> a >> b;

            adj[a].insert(b);
            adjt[b].insert(a);

            seen[a] = false;
            seen[b] = false;
        }

        for (auto it: adj)
            if (!seen[it.first])
                kosaraju(it.first, 1);
        
        for (auto& it: seen)
            it.second = false;

        for (int i = n - 1; i >= 0; i--)
        {
            if (!seen[order[i]])
            {
                circle.clear();
                kosaraju(order[i], 2);

                // Print circle
                cout << circle.front();
                for (int i = 1; i < circle.size(); i++)
                    cout << ", " << circle[i];
                cout << endl;
            }
        }
        adj.clear();adjt.clear();order.clear();seen.clear();

        cin >> n >> m;
        t++;
        if (n || m) cout << endl;
    }

    return 0;
}