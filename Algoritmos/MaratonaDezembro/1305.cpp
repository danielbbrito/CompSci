#include <bits/stdc++.h>
using namespace std;

bool Palindromo(int n);
bool Pares(int n);

int main()
{
    int n, num, incriveis=0;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> num;

        if (Palindromo(num) && Pares(num))
        {
            incriveis++;
        }
    }

    if (incriveis != n)
        cout << incriveis << " numeros incriveis\n";
    
    else
        cout << "sequencia incrivel!\n";

    return 0;
}

bool Palindromo(int n)
{
    if (n < 0)
        return false;
    int og = n;
    unsigned long long reverse = 0;

    do
    {
        reverse = (reverse * 10) + n % 10;
        n /= 10;
    } while (n >= 10);

    reverse = reverse * 10 + n;

    if (og == reverse || og < 10)
        return true;
    else
        return false;
}

bool Pares(int n)
{
    string n_str = to_string(n);
    int pares = 0;
    for (int i = 0; i < n_str.length(); i++)
        if ((int)(n_str[i] - 48) % 2 == 0)
            pares++;
    
    if (n_str.length() == pares)
        return true;
    
    return false;
}