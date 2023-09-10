#include <bits/stdc++.h>
using namespace std;

#define MAX 10000
int n;
int v[MAX];

int dp(int i)
{
    if (i >= n)
        return 0;

    int pega = v[i] + dp(i + 2);
    int npega = dp(i + 1);

    return max(pega, npega);
}

int main()
{
    cin >> n;
    for (int i = 0; i < 6; i++)
        cin >> v[i];
}