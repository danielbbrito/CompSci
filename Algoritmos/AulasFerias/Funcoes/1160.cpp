#include <bits/stdc++.h>

using namespace std;

int tempo(int pa, int pb, double g1, double g2)
{
    int anos = 0;

    while (pa <= pb && anos <= 100)
    {
        anos++;
        pa *= 1 + (g1 / 100);
        pb *= 1 + (g2 / 100);
    }

    return anos;
}

int main()
{
    int t, pa, pb;
    double g1, g2;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> pa >> pb >> g1 >> g2;

        int anos = tempo(pa, pb, g1, g2);

        if (anos <= 100)
            cout << anos << " anos." << endl;
        
        else
            cout << "Mais de 1 seculo." << endl;
    }

    return 0;
}