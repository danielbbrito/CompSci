#include <bits/stdc++.h>

using namespace std;

int main()
{
    int j=0;
    
    for (int i = 0; i < 6; i++)
    {
        char r;
        cin >> r;
        
        if (r == 'V')
            j++;
    }
    
    if (j == 5 || j == 6)
        cout << 1 << endl;
    else if (j == 3 || j == 4)
        cout << 2 << endl;
    else if (j == 1 || j == 2)
        cout << 3 << endl;
    
    else
        cout << -1 << endl;
        
    
    return 0;
}