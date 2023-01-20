#include <bits/stdc++.h>

using namespace std;

vector<int> adjlist[30];
bool seen[30];

// Finds out how many connected subgraphs there are
void dfs(int u)
{
    seen[u] = true;
    
    int sz = adjlist[u].size();
    for (int i = 0; i < sz; i++)
    {
        int v = adjlist[u][i];

        if (!seen[v])
            dfs(v);
    }
}

int main()
{
    int t;

    // Read number of test cases
    cin >> t;

    while (t--)
    {
        // Sets all nodes to be unseen;
        memset(seen, false, sizeof(seen));

        int count = 0;
        char max;

        // Read largest element in graph
        cin >> max;
        cin.ignore();
        int maxNode = max - 65;

        // Read all edges
        string edge;

        getline(cin, edge);
        while (!edge.empty())
        {
            int node1 = edge[0] - 65;
            int node2 = edge[1] - 65;

            adjlist[node1].push_back(node2);
            adjlist[node2].push_back(node1);
            getline(cin, edge);
        }

        // For each unvisited node in the graph
        for (int j = 0; j <= maxNode; j++)
        {
            if (!seen[j])
            {
                // Run dfs so that no node is checked twice
                dfs(j);
                count++;
            }
        }

        cout << count << "\n";

        if (t)
            cout << '\n';

        // Clear vectors
        for (int j = 0; j <= maxNode; j++)
            adjlist[j].clear();
    }

    return 0;
}