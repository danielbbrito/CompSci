#include <bits/stdc++.h>
using namespace std;
int n, x;
vector<int> coins;

int solve(int sum)
{
    if (sum < 0) return INT_MAX;
    if (sum == 0)
    {
        return 0;
    }
    int best = INT_MAX;

    for (auto c: coins)
    {
        best = min(best, solve(sum - c) + 1);
    }
    
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

   int ans = solve(x);


   cout << ans << endl;
   return 0;
}