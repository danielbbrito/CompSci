#include <bits/stdc++.h>

using namespace std;
struct pt {
    int x, y;
};

float cross_product(pt start, pt p1, pt p2)
{
    return (p1.x - start.x) * (p2.y - start.y) - (p1.y - start.y) * (p2.x - start.x);
}

string check(pt point, const vector<pt> &p)
{
    int ant[p.size()];
    if (cross_product(p[0], point, p[1]) > 0)
        ant[0] = 1;
    
    else ant[0] = 0;
    for (int i = 1; i < p.size() - 1; i++)
    {
        float cp = cross_product(p[i], point, p[i + 1]);

        if (!cp)
        {
            return "YES\n";
        }

        if (cp > 0)
        {
            ant[i] = 1;
            if (ant[i] != ant[i - 1])
                return "NO\n";
        }
        if (cp < 0)
        {
            ant[i] = 0;
            if (ant[i] != ant[i - 1])
                return "NO\n";
        }
    }

    return "YES\n";
}
int main()
{
    int n, d;
    cin >> n >> d;
    vector<pt> P;
    P.push_back({0, d});
    P.push_back({d, 0});
    P.push_back({n, n-d});
    P.push_back({n-d, n});
    P.push_back({0, d});

    int m;cin >> m;

    while (m--)
    {
        pt g;
        cin >> g.x >> g.y;
        cout << check(g, P);
    }
}