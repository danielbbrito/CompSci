#include <bits/stdc++.h>

using namespace std;
map<int, set<int>> al;
stack<int> st;
bool seen[205];
vector<int> low(205, -1), num(205, -1);
int counter, scc;
void tarjan(int s)
{
    low[s] = num[s] = counter;
    seen[s] = true;
    st.push(s);
    counter++;

    for (auto it: al[s])
    {
        if (num[it] == -1)
            tarjan(it);
        
        if (seen[it])
            low[it] = min(low[it], low[s]);
    }

    if (low[s] == num[s])
    {
        scc++;
        while (true)
        {
            int v = st.top(); st.pop();
            seen[v] = false;

            if (s == v) break;
        }
    }
}