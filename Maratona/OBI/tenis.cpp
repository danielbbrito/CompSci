#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b,c,d;
    
    cin >> a >> b >> c >> d;
    
    int min = INT_MAX;
    
    if (abs((a+b)-(c+d)) < min)
        min = abs((a+b)-(c+d));
    
    if (abs((a+c)-(b+d)) < min)
        min = abs((a+c)-(b+d));
    
    if (abs((a+d)-(b+c)) < min)
        min = abs((a+d)-(b+c));
        
    cout << min << endl;
    
    return 0;
}