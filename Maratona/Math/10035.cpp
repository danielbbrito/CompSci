#include <bits/stdc++.h>

using namespace std;

int main()
{
    string a, b;

    cin >> a >> b;
    while (a != "0" || b != "0")
    {
        int carry=0,ct=0;
        
        if (a.length() > b.length())
        {
            string buf = "";

            for (int i = 0; i < a.length() - b.length(); i++)
                buf += "0";

            b = buf + b;
        }

        else if (a.length() < b.length())
        {
            string buf = "";

            for (int i = 0; i < b.length() - a.length(); i++)
                buf += "0";

            a = buf + a;
        }

        for (int i = max(a.length() - 1, b.length() - 1); i >= 0; i--)
        {
            int calc = ((int)a[i] - 48) + ((int)b[i] - 48);

            if (carry)
                calc++;
            
            if (calc >= 10)
            {
                carry = 1;
                ct++;
            }
            else
                carry = 0;
        }

        if (ct == 0)
            cout << "No carry operation.\n";
        
        else if (ct == 1)
            cout << "1 carry operation.\n";
        
        else
            cout << ct << " carry operations.\n";

        cin >> a >> b;
    }

    return 0;
}