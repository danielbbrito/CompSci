#include <bits/stdc++.h>
using namespace std;
int n, x;
vector<int> coins;
vector<int> value;
vector<bool> ready;

int solve(int sum)
{
    if (sum < 0) return 1e9;

    if (sum == 0) return 0;
    if (ready[sum]) return value[sum];
    int best = 1e9;

    for (auto c: coins)
    {
        best = min(best, solve(sum - c) + 1);
    }
    
    ready[sum] = true;
    value[sum] = best;
    return best;
}
int main()
{
   cin >> n >> x;

   for (int i = 0; i < n; i++)
   {
        int a;cin>>a;

        coins.push_back(a);
   }
    
    value.assign(x + n + 1, 0);
    ready.assign(x + n + 1, false);
   int ans = solve(x);


   ans != 1e9 ? cout << ans << endl : cout << -1 << endl;
   return 0;
}