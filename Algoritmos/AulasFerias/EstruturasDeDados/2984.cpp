#include <bits/stdc++.h>
using namespace std;

int Parenteses(const string &s);

int main()
{
    string s;
    getline(cin, s);

    int assuntos = Parenteses(s);
    if (assuntos == 0)
        cout << "Partiu RU!\n";
    
    else
        cout << "Ainda temos " << assuntos << " assunto(s) pendente(s)!\n";
    
    return 0;
}

int Parenteses(const string &s)
{
    stack<char> par;
    
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
            par.push(s[i]);

        else if (par.size() > 0)
            par.pop();
    }

    return par.size();
}