#include <bits/stdc++.h>

using namespace std;
set<int>al[205];
bool seen[205], flag;
vector<int> color(205, -1);
int um, zero;
void check(int s)
{
    seen[s] = true;

    for (auto it: al[s])
    {
        if (!seen[it])
        {
            color[it] = abs(color[s] - 1);
            
            if (color[it])
                ++um;
            else
                ++zero;
                
            check(it);
        }
        
        else if (color[s] == color[it])
            flag = false;
    }
}

int main()
{
    int m;cin>>m;
    while (m--)
    {
        int n;
        cin>>n;
        for (int i = 1; i<= n; i++)
        {
            int am;cin >> am;
            while (am--)
            {
                int e;cin >> e;
                if (e <= n)
                {
                    al[i].insert(e);
                    al[e].insert(i);
                }
            }
        }
        
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!seen[i])
            {
                zero = 0;
                color[i] = 1;
                um = 1;
                flag = true;
                check(i);
                if (!flag) continue;
                else ans += max(um, zero);
            }
        }
        
        cout << ans << endl;
        for (int i = 1; i < 205; i++)
            al[i].clear();
            
        color.clear();
        memset(seen, false, sizeof(seen));
    }
}