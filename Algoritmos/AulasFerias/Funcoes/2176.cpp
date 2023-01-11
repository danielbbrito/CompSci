#include <bits/stdc++.h>

using namespace std;

void Paridade(string &s)
{
    int soma = 0;
    for (int i = 0; i < s.length(); i++)
        s[i] == '1' ? soma++ : soma;
    
    soma % 2 == 0 ? s += '0' : s += '1';
}

int main()
{
    string s;
    getline(cin, s);

    Paridade(s);

    cout << s << endl;

    return 0;
}