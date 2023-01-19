#include <iostream>
#include <vector>

using namespace std;

bool visited[100];
vector<int> adjlist[100];

bool dfs (int s, int e)
{
    visited[s] = true;

    if (s == e)
        return true;
    
    for (int i = 0; i < adjlist[s].size(); i++)
    {
        int v = adjlist[s][i];
        if (!visited[v])
            if (dfs(v, e))
                return true;
    }

    return false;
}
int main()
{
    int n;

    //Input number of edges in a given graph
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a, b;

        // Read edge nodes
        cin >> a >> b;

        // Store nodes' relationships
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }

    int s, e;

    // Read start and end nodes
    cin >> s >> e;

    cout << dfs(s, e) << endl;

    return 0;
}