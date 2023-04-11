#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    map<char, int> visits;

    cin >> n;
    cin.ignore();

    for (int i = 1; i <= n; i++)
    {
        string g;

        getline(cin, g);

        visits[g[0]] = 1;

        for (int i = 1; i < g.length(); i++)
        {
            if (visits.find(g[i]) == visits.end())
                visits[g[i]] = 1;

            else
            {
                if (g[i] == g[i-1])
                {
                    if (g[i-2] != g[i-3])
                        visits[g[i-2]]++;
                }
                
                else
                    visits[g[i]]++;
            }
        }

        printf("Case %d\n", i);

        for (auto it: visits)
            printf("%c = %d\n", it.first, it.second);
        
        visits.clear();
    }

    return 0;
}