#include <bits/stdc++.h>

using namespace std;

#define int long long
#define read(p) cin >> p.x >> p.y

struct ponto {
    int x, y;
};

inline float coefficient(ponto p1, ponto p2)
{
    return (p1.y - p2.y) / (float)(p1.x - p2.x);
}

inline float solve(ponto p2, ponto p3, float m)
{
    float c = m * (-p2.x) + p2.y;
    
    return m * p3.x + c;
}

int32_t main()
{
    int t;cin >> t;

    while (t--)
    {
        ponto p1, p2, p3;
        read(p1);
        read(p2);
        read(p3);

        float cross =  (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);

        if (cross < 0)
            cout << "RIGHT\n";

        else if (cross > 0)
            cout << "LEFT\n";
        
        else cout << "TOUCH\n";
    }
}