#include <bits/stdc++.h>
using namespace std;

#define MAX 1e9
vector<int>stone;
vector<int> dp;
int jumps(int s, int e)
{
    if (s > e) return MAX;
    if (s == e) return 0;
    
    if (dp[s] != MAX) return dp[s];

    return dp[s] = min(abs(stone[s] - stone[s + 1]) + jumps(s+1, e), abs(stone[s] - stone[s + 2]) + jumps(s + 2, e));
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

    cout << jumps(0, n - 1) << endl;
}