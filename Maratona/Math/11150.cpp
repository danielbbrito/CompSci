#include <bits/stdc++.h>

using namespace std;

int calculate(int n)
{
    
    int s = n;

    while (n >= 3)
    {
        s += n / 3;
        n = n / 3 + n % 3;
    }

    if (n == 2)
        s++;
    
    return s;
}

int main()
{
    int n;

    while (cin >> n)
    {
        cout << calculate(n) << endl;
    }
}