#include <bits/stdc++.h>

using namespace std;

double Raiz(unsigned int n)
{
    double base = 1 / 6;

    for (int i = 0; i < n; i++)
    {
        base += 6;

        base = 1 / base;
    }

    return base + 3.0;
}

int main()
{
    int N;

    cin >> N;

    cout << fixed << setprecision(10) << Raiz(N) << endl;

    return 0;
}