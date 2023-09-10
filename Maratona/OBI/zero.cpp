#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> sum;
    
    while (n--)
    {
        int t;
        cin >> t;
        
        if (!t && sum.size())
            sum.pop_back();
        else
            sum.push_back(t);
    }
    
    int s = 0;
    for (auto it: sum)
        s += it;
    
    cout << s << endl;
    
    return 0;
}