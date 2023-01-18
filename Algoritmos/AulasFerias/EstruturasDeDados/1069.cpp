#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int n, cont=0;
    stack<char> garimpo;
    string diamantes;

    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++)
    {
        getline(cin, diamantes);

        for (int j = 0; j < diamantes.length(); j++)
        {
            if (diamantes[j] == '<')
                garimpo.push(diamantes[j]);

            else if (diamantes[j] == '>' && garimpo.size() > 0)
            {
                garimpo.pop();
                cont++;
            }
        }

        cout << cont << endl;
        cont = 0;
        garimpo = stack<char>();
    }

    return 0;
}