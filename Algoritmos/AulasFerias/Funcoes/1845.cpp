#include <bits/stdc++.h>

using namespace std;

string Efilogo(string s)
{
    vector<char> f{'j', 'p', 's', 'v', 'b', 'x', 'z', 'j'};
    vector<char> F{'J', 'P', 'S', 'V', 'B', 'X', 'Z', 'J'};
    bool is_f;
    bool f_before = false;
    string mod = "";
    // Iterar sobre string
    for (int j = 0; j < s.length(); j++)
        for (int i = 0; i < 8; i++)
        {
            is_f = false;

            if (s[j] == f[i])
            {
                s[j] = 'f';
                is_f = true;
            }
            else if (s[j] == F[i])
            {
                s[j] = 'F';
                is_f = true;
            }
        }

        if (is_f)
        {
            if (!f_before)
            {
                mod += s;
                f_before = true;
            }
        }

        else
        {
            mod += s;
            f_before = false;
        }
    
    return mod;
}

int main()
{
    string s;

    while (getline(cin, s))
    {
        cout << Efilogo(s) << endl;
    }

    return 0;
}