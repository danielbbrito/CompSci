#include <bits/stdc++.h>

using namespace std;

int Impares(int n, int m)
{
    if (n - m <= 1)
    {
        return 0;
    }
    
    if (n % 2 == 0)
        n - 1;
    
    return n + Impares(n - 2, m);
    
}

int main()
{
    int n, m;

    cin >> n >> m;

    cout << Impares(n, m) << endl;

    return 0;
}