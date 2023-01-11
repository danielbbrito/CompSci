#include <bits/stdc++.h>

using namespace std;

string ConvHex(int n)
{
    string hex;
    while (n != 0)
    {
        int resto = n % 16;
        n /= 16;
        
        switch (resto)
        {
            case 10:
                hex = 'A' + hex;
                break;
            
            case 11:
                hex = 'B' + hex;
                break;

            case 12:
                hex = 'C' + hex;
                break;

            case 13:
                hex = 'D' + hex;
                break;

            case 14:
                hex = 'E' + hex;
                break;

            case 15:
                hex = 'F' + hex;
                break;
            
            default:
                hex = to_string(resto) + hex;
        }
    }

    return hex;
}

int main()
{
    int V;
    cin >> V;

    cout << ConvHex(V) << endl;

    return 0;
}