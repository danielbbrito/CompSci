#include <bits/stdc++.h>
using namespace std;

int main()
{
    int joao, pedro, n;

    cin >> n;
    
    do
    {
        cin >> pedro
            >> joao;
    }
    while (pedro > n || joao > n || pedro == joao || pedro < 0 || joao < 0);
    
    int dist = joao - pedro;

    dist /= 2;

    cout << ((joao - dist) - (dist - pedro)) / 2 << endl;

    return 0;
}