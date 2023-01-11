#include <bits/stdc++.h>

using namespace std;

int Falha(int n)
{
    bool flag = false;
    int ant=10001, medida, queda;

    cin >> ant;

    for (int i = 1; i < n; i++)
    {
        cin >> medida;

        if (!flag)
            if (medida < ant)
            {
                flag = true;
                queda = i;
            }
        ant = medida;
    }

    if (flag)
        return queda + 1;
    
    else
        return 0;
}

int main()
{
    int N;
    cin >> N;

    cout << Falha(N) << endl;

    return 0;
}