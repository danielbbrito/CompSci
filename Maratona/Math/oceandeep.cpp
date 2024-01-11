#include <bits/stdc++.h>

using namespace std;

string sum(string a, string b)
{
    int carry = 0;
    string result = "";
    int remains = max(a.length(), b.length()) - min(a.length(), b.length());

    for (int i = 0; i < remains; i++)
    {
        if (a.length() < b.length())
        {
            a = '0' + a;
        }

        else
        {
            b = '0' + b;
        }
    }

    for (int i = min(a.length(), b.length()) - 1; i >= 0; i--)
    {
        int aux = (a[i] - 48) + (b[i] - 48);

        if (carry)
        {
            aux += carry;
            carry = 0;
        }

        if (aux >= 10)
        {
            carry = aux / 10;

            aux = aux % 10;
        }

        result = to_string(aux) + result;
    }

    if (carry)
    {
        result = to_string(carry) + result;
    }

    return result;
}

string bin_dec(string s1)
{
    string s2 = "0";
    int power = s1.length() - 1;
    for (int i = 0; i <= s1.length(); i++)
    {
        if (s1[i] == '1')
        {
            s2 = sum(s2, to_string((int)pow(2, power)));
        }

        power--;
    }

    return s2;
}

int main()
{
    char a;

    while (cin >> a)
    {
        string string_binary = "";

        while (a != '#')
        {
            string_binary += a;
            cin >> a;
        }

        string string_decimal = bin_dec(string_binary);
    }

    return 0;
}