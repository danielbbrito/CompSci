#include <bits/stdc++.h>

using namespace std;
vector< pair<string, vector<int>>> ordenaMapa(map<string, vector<int>> &m);
void sortName(vector<pair<string, vector<int>>> &v);

int main()
{
    string modalidade, pais;
    map<string, vector<int>> tabela;

    // Ler até EOF
    while (getline(cin, modalidade))
    {
        // Ler cada país;
        for (int i = 0; i < 3; i++)
        {
            vector<int> placar(3, 0);
            getline(cin, pais);

            if (tabela.find(pais) == tabela.end())
                tabela.insert({pais, placar});

            tabela[pais].at(i)++;
        }
    }

    vector<pair<string, vector<int>>> final = ordenaMapa(tabela);
    cout << "Quadro de medalhas\n";

    for (vector< pair<string, vector<int>>>::iterator itr = final.begin(); itr != final.end(); itr++)
        cout << itr->first << ' ' << itr->second.at(0) << ' ' << itr->second.at(1) << ' ' << itr->second.at(2) << endl;
    
    return 0;
}

void ordenaPais(vector<pair<string, vector<int>>> &v)
{
    bool flag = true;
    while (flag)
    {
        for (int i = 0; i < v.size(); i++)
        {
            flag = false;
            if (v.at(i).second == v.at(i + 1).second)
            {
                if (v.at(i).first > v.at(i + 1).first)
                {
                    pair<string, vector<int>> aux = v.at(i);
                    v.at(i) = v.at(i + 1);
                    v.at(i + 1) = aux;
                    flag = true;
                }
            }
        }
    }
}

vector< pair<string, vector<int>>> ordenaMapa(map<string, vector<int>> &m)
{
    string menor;
    vector< pair<string, vector<int>>> ordenado;
    
    while(ordenado.size() < m.size())
    {
        map<string, vector<int>>::iterator itr;
        for (itr = m.begin(); itr != m.end(); itr++)
        {
            if (itr->second < next(itr, 1)->second)
            {
                menor = itr->first;
            }
        }

        ordenado.push_back({menor, m[menor]});
        m.erase(itr);
    }
    ordenaPais(ordenado);
    return ordenado;
}
