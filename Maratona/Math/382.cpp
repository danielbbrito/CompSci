#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int n_size = 0;
    cin >> n;
    cout << "PERFECTION OUTPUT\n";
    while (n != 0)
    {
        if (to_string(n).length() > n_size)
            n_size = to_string(n).length();

        int q = 1;
        for (int i = 2; i < sqrt(n); i++)
        {
            if (n % i == 0)
            {
                q += i;

                q += n / i;
            }
        }

        for (int i = 0; i < 5 - to_string(n).length(); i++)
            cout << ' ';
        cout << n;
        if (q == n && n != 1)
            cout << "  PERFECT\n";
        
        else if (q < n || n == 1)
            cout << "  DEFICIENT\n";
        
        else
            cout << "  ABUNDANT\n";
        
        cin >> n;
    }

    cout << "END OF OUTPUT\n";
    return 0;
}