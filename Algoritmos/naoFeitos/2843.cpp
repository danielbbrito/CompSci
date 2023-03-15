#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int rodada[n];
    int tempos[n];
    int reacao[n];

    vector<int> part;

    for (int i = 0; i < n; i++)
    {
        int r, e;
        cin >> r >> e;

        reacao[i] = r;
        tempos[i] = e;
    }
    string txt;
    cin >> txt;

    for (int i = 0; i < n; i++)
        part.push_back(reacao[i] + tempos[i] * txt.size());
    
    // Realizar rodadas
    for (int j = 0; part.size() > 1; j++)
    {
        for (int i = 0; i < part.size(); i++)
        {
            if (*(part.begin() + i) >= *(part.begin() + i + 1))
            {
                rodada[i + 1 + j] = j;
                part.erase(part.begin() + i + 1);
            }

            else
            {
                rodada[i + j] = j;
                part.erase(part.begin() + i);
            }
        }
    }

    // Imprimir
    cout << rodada[0];
    for (int i = 1; i < n; i++)
        cout << ' ' << rodada[i];
    cout << endl;
}