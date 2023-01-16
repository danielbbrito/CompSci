#include <bits/stdc++.h>

using namespace std;

int main()
{
    int m, n;
    
    string problema; 
    multiset<string> vida, disciplina;

    cin >> n
        >> m;

    for (int i = 0; i < n * m; i++)
    {
        cin >> problema;
        cin.ignore();

        if (problema.find("V") != string::npos)
            vida.insert(problema);
        else
            disciplina.insert(problema);
    }

    for (multiset<string>::reverse_iterator itr = vida.rbegin(); itr != vida.rend(); itr++)
        cout << *itr << endl;
    
    for (multiset<string>::reverse_iterator itr = disciplina.rbegin(); itr != disciplina.rend(); itr++)
        cout << *itr << endl;
    
    return 0;
}