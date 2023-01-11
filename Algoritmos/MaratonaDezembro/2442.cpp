#include <bits/stdc++.h>
using namespace std;

int main()
{
    string bolo;
    cin >> bolo;

    while (bolo != "FIM")
    {
        if (bolo == "CHOCOLATE")
            cout << "JOANA\n";
        
        else if (bolo == "CENOURA")
            cout << "MARI\n";
        
        else
            cout << "VIXE ESTRAGOU\n";
        
        cin >> bolo;
    }
}