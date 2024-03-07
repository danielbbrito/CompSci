#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main()
{
    int score1 = 0,score2=0;

    int n;cin>>n;
    
    while (n--)
    {
        int tak, aok;
        cin>>tak>>aok;
        score1+=tak;
        score2+=aok;
    }

    if (score1>score2) cout << "Takahashi\n";
    else if (score1 < score2) cout << "Aoki\n";
    else cout << "Draw\n";
}