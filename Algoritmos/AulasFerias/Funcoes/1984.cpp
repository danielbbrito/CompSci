#include <bits/stdc++.h>

using namespace std;

string InverteNumero(string n)
{
    if (n == "")
    {
        return "";
    }

    return InverteNumero(n.substr(1, string::npos)) + n[0];
}

int main()
{
    string n;

    cin >> n;

    cout << InverteNumero(n) << endl;
}