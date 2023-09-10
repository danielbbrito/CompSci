#include <bits/stdc++.h>

using namespace std;

bool check(int sz, string s)
{
    string sub = s.substr(0, sz);
    
    for (int i = sz; i < s.length(); i += sz)
    {
        string sub2 = s.substr(i, sz);
        
        for (int j = 0; j < sub2.length(); j++)
        {
            string sc = sub;
            int p = sc.find(sub2[j]);
            
            if (p == string::npos)
                return false;
                
            sc.erase(p,1);
            sub2.erase(p, 1);
        }
    }
    
    return true;
}

int main()
{
    int n;
    
    string s;
    
    cin >> n >> s;
    
    bool flag = false;
    for (int i = 1; i <= s.length() / 2 && !flag; i++)
    {
        flag = check(i, s);
        
        if (flag)
        {
            cout << s.substr(0, i) << endl;
        }
    }
    
    if (!flag)
        cout << "*" << endl;
}