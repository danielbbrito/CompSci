#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> am(15, 0);

        for (int i = 1; i <= n; i++)
        {
            string is = to_string(i);

            for (int j = 0; j < is.length(); j++)
                am[(int)is[j] - 48]++;
        }

        cout << am.front();
        for (int i = 1; i < 10; i++)
            cout << ' ' << am[i];

        cout << endl;
    }

    return 0;
}