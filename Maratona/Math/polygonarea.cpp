#include <bits/stdc++.h>
using namespace std;

struct Pt {
    int x, y;
};

#define read(p) cin >> p.x >> p.y
#define int long long

int cross_product(Pt s, Pt p1, Pt p2) {return (p2.x - s.x)*(p1.y - s.y) - (p2.y - s.y)*(p1.x - s.x);}

int32_t main()
{
    int n;cin>>n;

    vector<Pt> polygon;
    while (n--)
    {
        Pt p;
        read(p);
        polygon.push_back(p);
    }

    int area = 0;


    for (int i = 1; i < polygon.size() - 1; i++)
    {
        area += cross_product(polygon[0], polygon[i], polygon[i + 1]);
    }
    
    cout << abs(area) << endl;
}