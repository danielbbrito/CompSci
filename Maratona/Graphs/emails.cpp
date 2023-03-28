#include <bits/stdc++.h>

using namespace std;
int adjlist[50001];
vector<bool> seen(50001);

int dfs(int s, int c)
{
    seen[s] = true;

    if (!seen[adjlist[s]])
        return c + dfs(adjlist[s], 1);
    
    return 1;
}

int main()
{
    int t;
    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        int n;
        cin >> n;

        int maior=0, escolhido=0;

        for (int j = 1; j <= n + 5; j++)
            adjlist[j] = 0;

        for (int j = 0; j < n; j++)
        {
            int a, b;
            cin >> a >> b;
            adjlist[a] = b;
        }

        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
                seen[k] = false;

            int curr = dfs(j, 0);
            
            if (curr > maior)
            {
                maior = curr;
                escolhido = j;
            }
        }

        cout << "Case " << i << ": " << escolhido << endl;

    }
    return 0;
}