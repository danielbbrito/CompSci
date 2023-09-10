#include <bits/stdc++.h>
using namespace std;

map<int, set<int>> adj;
bool seen[105];
int id[105];
int low[105];
bool point[105];
int edc;
int ct;

void dfs(int root, int s, int p)
{
    if (root == p) edc++;
    seen[s] = true;
    // Id starts is parent's id + 1
    id[s] = id[p] + 1;
    // Lowest reachable id starts at itself
    low[s] = id[s];

    for (auto it: adj[s])
    {
        if (!seen[it])
        {
            dfs(root, it, s);

            low[s] = min(low[s], low[it]);

            // If the current id is lesser than the lowest rwachable from the next, an articulation point has been found from a bridge
            // If it is equal, the articulation point has been found because there is a cycle formed by the current vertex
            if (id[s] <= low[it] && !point[s])
            {
                ct++;
                point[s] = true;
            }
        }
        else
        {
            low[s] = min(low[s], id[it]);
        }
    }

}

void breakString(string s)
{
    string init = "";
    string n = "";
    int i = 0;
    
    while (s[i] != ' ')
    {
        init += s[i]; i++;
    }
    i++;
    int ss = stoi(init);
    for (; i<s.length(); i++)
    {
        while (s[i] != ' ' && s[i] != '\0')
        {
            n += s[i]; i++;
        }
        
        int e = stoi(n);
        adj[ss].insert(e);
        adj[e].insert(ss);
        n = "";
    }
}
int main()
{
    int n;

    cin >> n;

    while (n)
    {

        string line;
        cin.ignore();
        getline(cin, line);
        while (line != "0")
        {
            breakString(line);
            
            getline(cin, line);
        }
        memset(seen, false, sizeof seen);
        memset(id, 0, sizeof id);
        memset(point, false, sizeof point);
        for (int i = 1; i <= n; i++)
        {
            if (!seen[i])
            {
                edc = 0;
                ct = 0;
                dfs(i, i, 0);

                if (edc <= 1)
                    ct--;
            }
        }

        cout << ct << endl;
        adj.clear();
        cin >> n;
    }
}