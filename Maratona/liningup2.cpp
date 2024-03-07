#include <bits/stdc++.h>

using namespace std;

#define int long long


int32_t main()
{
    int n;cin>>n;
    int inverse[n+1];
    int first;
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        int a;cin>>a;

        inverse[a] = i;

        if (a == -1)
            first = i;
    }

    q.push(first);

    while (q.size() < n)
    {
        q.push(inverse[first]);
        first = inverse[first];
    }

    cout << q.front();q.pop();

    while (q.size())
    {
        cout << ' ' << q.front();
        q.pop();
    }

    cout << endl;
    return 0;
}