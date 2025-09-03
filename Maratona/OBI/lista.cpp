#include <bits/stdc++.h>
using namespace std;
int ct;

vector<int> ls;


int main()
{
    ct = 0;
    int n;
    cin >> n;
    while (n--)
    {
        int a;
        cin >> a;
        ls.push_back(a);
    }

    palindrome(0, ls.size() - 1);

    cout << ct << endl;
        
}