#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef struct {
    int v;
    int w;
} pii;
vector<pii> seq;

int knapsack(int i, int W)
{
    if (W < 0)
        return 0;

    int best = -1;

    for (int j = i + 1; j < seq.size(); j++)
    {
        best = max(best, seq[i].v + knapsack(i + j, W - seq[i].w));
    }

    return best;
}

int32_t main()
{
    int n, w;cin>>n>>w;

    for (int i = 0; i < n; i++)
    {
        pii s;
        cin >> s.v >> s.w;

        seq.push_back(s);
    }
    knapsack(0, w);

}