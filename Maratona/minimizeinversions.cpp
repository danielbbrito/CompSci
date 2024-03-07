#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;cin>>t;

    while (t--)
    {

        int n;cin>>n;
        int p1[n], p2[n];
        for (int i = 0; i < n;i++)
        {
            cin >> p1[i];
        }

        for (int i = 0; i < n; i++)
        {
            cin >>p2[i];
        }
        int inv1 = 0, inv2 = 0;

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (p1[i] > p2[j])
                {
                    if (p2[i] >= p2[j])
                    {
                        swap(p1[i], p1[j]);
                        swap(p2[i], p2[j]);
                    }
                }

                else if (p2[i] > p2[j])
                {
                    if (p1[i] >= p2[j])
                    {
                        swap(p1[i], p2[j]);
                        swap(p2[i], p2[j]);
                    }
                }
            }
        }

        cout << p1[0];
        for (int i = 1; i < n; i++)
            cout << ' ' << p1[i];

        cout << endl;

        cout << p2[0];
        for (int i = 1; i < n; i++)
            cout << ' ' << p2[i];

        cout << endl;

        
    }
}