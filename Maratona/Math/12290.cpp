#include <bits/stdc++.h>

using namespace std;

bool check(int n)
{
    string ns = to_string(n);
    return n % 7 == 0 || ns.find("7") != string::npos;
}

int calculate(int n, int m, int k)
{
    int ct = 0;
    int flag = 0;
    int ans = -1;
    int u = 1;
    while (true)
        {
            // Check ascending
            for (int i = !flag ? 1 : 2; i <= n; i++)
            {
                if (check(u) && i == m)
                {
                    ct++;
                    ans = u;

                    if (ct == k)
                        return ans;
                }

                u++;
            }

            // check descending
            for (int i = n - 1; i >= 1; i--)
            {
                if (check(u) && i == m)
                {
                    ct++;
                    ans = u;
                    if (ct == k)
                        return ans;
                }

                u++;
            }

            flag = 1;
        }

        return ans;
}

int main()
{
    int n,m,k;

    cin >> n >> m >> k;

    while (n || m || k)
    {
        cout << calculate(n, m, k) << endl;
        cin >> n >> m >> k;
    }
    
    return 0;
}