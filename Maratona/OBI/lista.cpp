#include <bits/stdc++.h>

using namespace std;
int ct;

vector<int> ls;

void solve(int s, int e)
{
    if (s >= e) return;
    
    if (ls[s] == ls[e])
        return solve(s + 1, e - 1);
        
    if (ls[s] > ls[e])
    {
        // Contrair
        int sum = ls[e] + ls[e - 1];
        
        ls[e] = sum;ls.erase(ls.begin() + e - 1);
        ct++;
        
        return solve(s + 1, e - 1);
    }
    
    else if (ls[s] < ls[e])
    {
        int sum = ls[s] + ls[s + 1];
        
        ls[s] = sum; ls.erase(ls.begin() + s + 1);
        ct++;
        
        return solve(s + 1, e - 1);
    }
}


int main()
{
    ct = 0;
    int n;
    
    cin >> n;
    
    while (n--)
    {
        int a;cin>>a;
        ls.push_back(a);
    }
    
    int sz = ls.size() - 1;
    solve(0, sz);
    
    cout << ct << endl;
}