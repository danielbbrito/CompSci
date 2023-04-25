#include <bits/stdc++.h>

using namespace std;

int main()
{
    string a, b;

    cin >> a >> b;
    while (a != "0" && b != "0")
    {
        int ct = 0;
        int carry = 0;
        for (int i = min(a.length()-1, b.length()-1); i >= 0; i--)
        {
            if (((int)a[i] - 48) + ((int)b[i] - 48) >= 10)
            {
                ct++;
                carry = 1;
            }
            else if (carry == 1)
                ct++;
        }

        if (!ct)
            cout << "No";
        
        else
            cout << ct;

        cout << " carry operation.\n";

        cin >> a >> b;
    }

    return 0;
}