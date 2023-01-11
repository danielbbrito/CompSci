#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, procura;
    cin >> n;

    int items[n];

    for (int i = 0; i < n; i++)
    {
        cin >> items[i];
    }

    for (int i = 0; i < 3; i++)
    {
        cin >> procura;

        int flag = 0;

        for (int j = 0; j < n && flag == 0; j++)
        {
            if (items[j] == procura)
            {
                flag = 1;
                cout << "ID " << procura << ": item encontrado\n";
            }
        }

        if (flag == 0)
        {
            cout << "ID " << procura << ": sem resultados\n";
        }
    }

    return 0;
}