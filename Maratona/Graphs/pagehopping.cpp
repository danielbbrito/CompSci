#include <bits/stdc++.h>

using namespace std;

int main()
{
    int am[105][105];

    int a, b, t = 1;
    cin >> a >> b;

    while (a && b)
    {
        int mx = max(a, b);
        set<int> seen;
        for (int i = 0; i < 105; i++)
            for (int j = 0; j < 105; j++)
                if (i != j)
                    am[i][j] = 1000000000;
                else
                    am[i][j] = 0;
                    
    
        am[a][b] = 1;

        cin >> a >> b;
        
        while (a || b)
        {
            mx = max(max(a, b), mx);
            if (seen.find(a) == seen.end()) seen.insert(a);
            if (seen.find(b) == seen.end()) seen.insert(b);

            am[a][b] = 1;
            cin >> a >> b;
        }

        int sz = seen.size();seen.clear();
        for (int k = 1; k <= mx; k++)
        {
            for (int i = 1; i <= mx; i++)
            {
                for (int j = 1; j <= mx; j++)
                {
                    //cout << "For nodes " << i <<" and " << j << " am[i][j] is " << am[i][j] << " am[i][k] is " << am[i][k] << " and am[k][j] is " << am[k][j] << endl;
                    am[i][j] = min(am[i][j], am[i][k] + am[k][j]);
                }

                
            }
            
        }
        float count = (float)sz * (sz - 1);

        int sum = 0;
        for (int i = 1; i <= mx; i++)
            for (int j = 1; j <= mx; j++)
                if (am[i][j] < 1000000000)
                    sum += am[i][j];

        cout << fixed << setprecision(3) << "Case " << t << ": average length between pages = " << sum / count  << " clicks\n";
        cin >> a >> b;
        t++;
    }
}