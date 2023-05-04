#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, t, flag=0;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int sum1 = -1, sum2 = 1, sum3 = -1, sum4 = 1;
        int i = 2;
        int ct1 = 1, ct2 = 1, ct3 = 1;
        while (sum1 != n && sum2 != n && sum3 != n && sum4 != n)
        {
            if (sum1 < n)
            {
                sum1 += i;
                sum3 -= i;
                ct1++;
            }
            else if (sum1 > n)
            {
                sum1 -= i;
                sum3 += i;
                ct1++;
            }

            if (sum2 < n)
            {
                sum2 += i;
                sum4 -= i;
                ct2++;
            }

            else if (sum2 > n)
            {
                sum2 -= i;
                sum4 += i;
                ct2++;
            }

            

            i++;
        }

        cout << min(ct1, ct2) << endl;

        if (t)
            cout << endl;
    }

    return 0;
}