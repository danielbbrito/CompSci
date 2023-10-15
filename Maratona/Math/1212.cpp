#include <bits/stdc++.h>

using namespace std;

int main()
{
    string a, b;

    cin >> a >> b;

    while (a != "0" || b != "0")
    {

        int carry = 0;
        int amount = 0;
        if (a.length() > b.length())
        {
            while (b.length() < a.length())
            {
                b = '0' + b;
            }
        }

        else if (a.length() < b.length())
        {
            while (a.length() < b.length())
            {
                a = '0' + a;
            }
        }

        for (int i = a.length() - 1; i >= 0; i--)
        {
            int sum = (a[i] - 48) + (b[i] - 48) + carry;

            if (sum >= 10)
            {
                amount++;
                carry = sum / 10;
                sum = sum % 10;
            }
            else
                carry = 0;
        }

        if (amount == 1)
            cout << amount << " carry operation.\n";

        else if (!amount)
            cout << "No carry operation.\n";

        else
            cout << amount << " carry operations.\n";

        amount = 0;
        carry = 0;
        cin >> a >> b;
    }
}