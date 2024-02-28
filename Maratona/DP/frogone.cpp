#include <bits/stdc++.h>
using namespace std;
#define MAX 1e9
vector<int>stone;

vector<int> dp;
int jumps(int s, int e, int cost)
{
    if (dp[s] != MAX) return dp[s];
    if (s == e) return cost;
    if (s > e) return MAX;

    return dp[s] = (min(
        jumps(s + 1, e, abs(stone[s+1] - stone[s])), 
        jumps(s + 2, e, abs(stone[s+2] - stone[s]))) 
        + cost);
}

int main()
{
    int n;cin>>n;
    stone.assign(n, MAX);
    dp.assign(n, MAX);
    for (int i = 0; i < n; i++)
    {
        int s;cin>>s;
        stone[i] = s;
    }

    cout << jumps(0, n - 1, 0) << endl;
}