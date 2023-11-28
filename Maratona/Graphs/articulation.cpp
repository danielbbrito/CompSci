#include <bits/stdc++.h>

using namespace std;

int num[100], low[100], bridges[100][100], parents[100], child;
bool seen[100], points[100];
map<int, set<int>> al;
void dfs(int s, int root, int ct)
{
    seen[s] = true;
    num[s] = low[s] = ct; // iteration counter

    for (auto it: al[s])
    {
        if (!seen[s])
        {
            parents[it] = s;
            if (root == s) child++; // Count root's children, special case
            dfs(it, root, ct + 1);

            if (low[it] >= num[s]) // If there is no cycle, there is only one path from it to s, meaning s is an articulation point
                points[s] = 1;

            if (low[it] > num[s]) // There is no cycle and no double edge, there is a bridge
            {
                bridges[s][it] = 1;
            }
            
            low[s] = min(low[s], low[it]); // If it can reach a vertex with an iteration counter lower than itself, then so can s, since they are biconnected
        }

        else if (it != parents[s]) // There is a cycle formed by more than two vertices
        {
            low[s] = min(low[s], num[it]);
        }
    }

}

int main()
{
    int n, m;cin >>n >>m;

    while(m--)
    {
        int a, b;cin>>a>>b;
        al[a].insert(b);
        al[b].insert(a);
    }

    for (int i = 0; i < n; i++)
    {
        if (!seen[i])
        {
            child = 0;
            dfs(i, i, 0);
            points[i] = (child > 1);
        }
    }
}