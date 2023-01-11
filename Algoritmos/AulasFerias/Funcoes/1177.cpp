#include <bits/stdc++.h>

using namespace std;

void ConstroiVetor(int *v, int t)
{

    for (int i = 0, j = 0; i < 1000; i++, j++)
    {
        if (j == t)
            j = 0;

        v[i] = j;
    }

    return;
}

int main()
{
    int t, n[1000];

    cin >> t;

    ConstroiVetor(n, t);

    for (int i = 0; i < 1000; i++)
    {
        cout << "N[" << i << "] = " << n[i] << endl;
    }

    return 0;
}