#include <bits/stdc++.h>
using namespace std;
int cost = INT_MAX;;

int jumps(int s, int e, int stone[])
{
    if (s >= e)
    {
        return 0;
    }

    cost = min(jumps(s + 1, e, stone) + abs(stone[s] - stone[s + 1]), jumps(s + 2, e, stone));
}

int main()
{
    int n;
    int stone[n];

    for (int i = 0; i < n; i++)
    {
        int s;cin>>s;
        stone[i] = s;
    }

    jumps(0, n - 1, stone);

    cout << cost << endl;
}