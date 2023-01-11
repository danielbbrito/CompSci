// Segfault
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m1, m2, repetidas=0, buffer;
    
    cin >> n
        >> m1
        >> m2;

    vector<int> b1, b2, rep;

    // Ler primeiro baralho
    for (int i = 0; i < m1; i++)
    {
        cin >> buffer;
        b1.push_back(buffer);
    }

    for (int  i = 0; i < m2; i++)
    {
        cin >> buffer;
        b2.push_back(buffer);
    }

    // Identificar cartas repetidas
    int k = 0, l=0;
    for (int i = 0; i < m1; i++)
    {
        int flag;
        for (int j = 0; j < m2; j++)
        {
            flag = 0;
            if (b1[i] == b2[j])
            {
                rep[k] = b1[i];
                k++;
                rep[k] = b2[j];
                k++;
                repetidas += 2;
                flag = 1;
            }
        }
    }

    b1.insert(b1.end(), b2.begin(), b2.end());

    // remove duplicates
    for (int i = 0; i < b1.size(); i++)
    {
        for (int j = 0; j < rep.size(); j++)
        {
            if (b1[i] == rep[j])
            {
                b1.erase(b1.begin() + 1);
            }
        }
    }

    sort(b1.begin(), b1.end());

    cout << repetidas;

    for (int i = 0; i < rep.size(); i++)
    {
        cout << rep[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < b1.size(); i++)
    {
        cout << b1[i] << " ";
    }
}