/*
* SSSP algorithm which allows for negative weights and is capable of checking for negative weight cycles.
* Slower than both BFS and Dijkstra's
*/
#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

int n; // Number o edges

map<int, set<pair<int,int>>> adjlist;

int bellmanFord(int s, int e)
{
    // Initialize distance and path containers
    vector<int> dist(n + 1, INF);
    int path[n+1];
    dist[s] = 0;
    path[s] = s;

    // Flag for stopping early if no changes to the shortest path estimates have been found
    bool changed = true;

    for (int i = 0; i < n - 1 && changed; i++) // Relax EACH edge at most V - 1 times
    {
        changed = false;
        for (int j = 1; j <= n; j++) // Check all adjlists
        {
            if (dist[j] != INF) // Only relax edges that do not have INF for distance (prevents overflow)   
                for (auto &[v, w]: adjlist[j]) // Relax edges
                {
                        dist[v] = min(dist[v], dist[j] + w);
                        changed = true;
                }
        }
    }

    // Now we check for negative weights cycles
    bool negativeCycle = false;
    for (int i = 1; i <= n && !negativeCycle; i++)
    {
        if (dist[i] != INF)
            for (auto &[v, w]: adjlist[i])
            {
                if (dist[v] > dist[i] + w)
                    negativeCycle = true;
            }
    }
    
    return negativeCycle ? -1 : dist[s];
}