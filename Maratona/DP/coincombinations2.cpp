#include <bits/stdc++.h>

using namespace std;
#define int long long
vector<int> coins;
vector<int> dp;
int mod = 1e9+7;
int solve(int amount, int prev)
{
    if (amount < 0) return 0;

    if (amount == 0) return 1;

    if (dp[amount] != -1) return dp[amount];
    int sum = 0;

    for (auto c: coins)
    {
        if (c >= prev)
        sum += solve(amount - c, c);
    }

    return dp[amount] = sum % mod;
}
int32_t main()
{
    int n, x;
    cin >> n >> x;
    dp.assign(x + 1, -1);
    while (n--)
    {
        int a;cin>>a;
        coins.push_back(a);
    }

    int ans = solve(x, coins.front());

    cout << ans << endl;
}