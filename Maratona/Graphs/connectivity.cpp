#include <bits/stdc++.h>

using namespace std;

set<int> adjlist[30];
bool seen[30];

// Finds out how many connected subgraphs there are
void dfs(int u)
{
    seen[u] = true;
    
    for (auto it: adjlist[u])
    {
        if (!seen[it])
            dfs(it);
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

            adjlist[node1].insert(node2);
            adjlist[node2].insert(node1);
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