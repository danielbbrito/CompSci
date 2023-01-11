#include <bits/stdc++.h>

using namespace std;

void Presentes(vector<int> &p, vector<int> &d, int k)
{
    for (int i = 0; i < d.size() - 1; i++)
    {
        int menor = i;
        for (int j = i; j < d.size(); j++)
        {
            if (d.at(j) > d.at(menor))
            {
                menor = j;
            }
        }
        int aux1 = d.at(i);
        d.at(i) = d.at(menor);
        d.at(menor) = aux1;

        int aux2 = p.at(i);
        p.at(i) = p.at(menor);
        p.at(menor) = aux2;

    }
    
    return;
}

int main()
{
    int t, n, k, id, h, w, l;
    vector<int> ids;
    vector<int>dim;
    
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> n >> k;

        for (int j = 0; j < n; j++)
        {
            cin >> id;
            ids.push_back(id);
            cin >> h >> w >> l;
            dim.push_back(h * w * l);
        }

        Presentes(ids, dim, k);

        if (dim.at(0) == dim.at(1) && ids.at(0) > ids.at(1))
        {
            int aux = dim.at(0);
            dim.at(0) = dim.at(1);
            dim.at(1) = aux;
        }

        else
            cout << ids.at(0);

        
        for (vector<int>::iterator itr = ids.begin() + 1; itr != ids.begin() + k; itr++)
        {
            cout << ' ' << *itr;
        }

        cout << endl;
    }

    return 0;
}