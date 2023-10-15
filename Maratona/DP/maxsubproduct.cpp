#include <bits/stdc++.h>

using namespace std;
#define int long long
int currmax = 0;

void solve(const vector<int> &list, int i, int prod)
{
    if (i == list.size())
    {
        if (prod > currmax)
            currmax = prod;
        return;
    }
    
    solve(list, i + 1, prod * list[i]);
        
    solve(list, i + 1, list[i]);
    
}
int32_t main()
{
  
    int a;
    while (cin >> a)
    {
        vector<int> input;
        
        while (a != -999999)
        {
            input.push_back(a);
            
            cin >> a;
        }
        
        currmax = INT_MIN;
        solve(input, 0, 1);
        cout << currmax << endl;
    }
}