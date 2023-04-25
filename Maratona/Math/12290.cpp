#include <bits/stdc++.h>

using namespace std;

bool check(int n)
{
    string ns = to_string(n);
    return n % 7 == 0 || ns.find("7") != string::npos;
}

int main()
{
    int n,m,k;

    cin >> n >> m >> k;

    while (n || m || k)
    {
        int ct = 0;
        int q = -1;
        for (int i = 1; ct < k; i++)
        {
            if (i % 2 == 0)
                q = ((n-1) * i) + 1 - (m - 1);
            else
                q = (((n-1) * (i - 1)) + n) - (n - m);


            //cout << i << ' ' << q << endl;
            //this_thread::sleep_for(std::chrono::seconds{1});
            if (check(q) && q >=0)
                ct++;
        }

        cout << q << endl;

        cin >> n >> m >> k;
    }
}