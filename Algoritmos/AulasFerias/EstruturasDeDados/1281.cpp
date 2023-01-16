#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, p;
    map<string, float> items;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string item;
        float total = 0;

        cin >> m;

        for (int j = 0; j < m; j++)
        {
            float preco;
            cin >> item >> preco;
            items[item] = preco;
        }

        cin >> p;

        for (int k = 0; k < p; k++)
        {
            int qtd;

            cin >> item >> qtd;

            total += items[item] * qtd;
        }

        cout << fixed << setprecision(2) << "R$ " << total << endl;
        items.clear();
    }

    return 0;
}
