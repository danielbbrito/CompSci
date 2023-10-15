/**
 * The technique used in this problem is called the shoelace theorem
 * Triangularization does not work very well for concave polygons :(
*/
#include <bits/stdc++.h>

using namespace std;
#define int long long
#define double long double
#define read(p) cin >> p.x >> p.y

struct pt
{
    int x, y;
};

vector<pt> points;

double solve()
{
    double area = 0.0, x1, x2, y1, y2;

    for (size_t i = 0; i < points.size() - 1; i++)
    {
        x1 = points[i].x;
        x2 = points[i + 1].x;
        y1 = points[i].y;
        y2 = points[i + 1].y;

        area += (x1 * y2 - x2 * y1);
    }

    return fabs(area);
}
int32_t main()
{
    int n;
    cin >> n;
    while (n--)
    {
        pt p;
        read(p);

        points.push_back(p);
    }
    points.push_back(points.front());

    cout << (int)solve() << endl;
}