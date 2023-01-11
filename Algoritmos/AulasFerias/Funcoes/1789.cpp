#include <bits/stdc++.h>

using namespace std;

int VerificaLesma(vector<int> &L)
{
    int min = *max_element(L.begin(), L.end());

    if (min < 10)
        return 1;
    
    else if (min < 20)
        return 2;
    
    return 3;
}

int main()
{
    int l, v;
    vector<int> vel;

    while (cin >> l)
    {
        for (int i = 0; i < l; i++)
        {
            cin >> v;
            vel.push_back(v);
        }

        cout << VerificaLesma(vel) << endl;
        vel.clear();
        vel.shrink_to_fit();
    }

    return 0;
}