#include <bits/stdc++.h>

using namespace std;

int CalculaPontos(int b, int ai, int di, int lvl)
{
    if (lvl % 2 == 0)
        return ((ai + di) / 2) + b;

    return ((ai + di) / 2);
}

string Ganhador(int a, int b)
{
    if (a > b)
        return "Dabriel\n";
    
    else if (a < b)
        return "Guarte\n";
    
    return "Empate\n";
}

int main()
{
    int score1, score2, atk, def, bonus, lvl, t;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> bonus >> atk >> def >> lvl;
        score1 = CalculaPontos(bonus, atk, def, lvl);
        cin >> atk >> def >> lvl;
        score2 = CalculaPontos(bonus, atk, def, lvl);

        cout << Ganhador(score1, score2);
    }

    return 0;
}