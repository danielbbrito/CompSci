#include <bits/stdc++.h>
using namespace std;

#define read(p) cin >> p.x >> p.y
#define int long long
#define double long double

struct pt {
    int x, y;
};


// Evaluate the orientation for the points in one segment and one point in the other
int orientation(pt p1, pt p2, pt p3)
{
    int slope = (p1.y - p2.y) * (p2.x - p3.x) - (p2.y - p3.y) * (p1.x - p2.x);

    if (!slope) return 0; // Collinear
    else if (slope > 0) return 1; // clockwise
    return 2; // counterclockwise
}

// Checks if p1 lies on segment p2p3
int collinear(pt p1, pt p2, pt p3)
{
    return (p1.x >= min(p2.x, p3.x) && p1.x <= max(p2.x, p3.x) && p1.y >= min(p2.y, p3.y) && p1.y <= max(p2.y, p3.y));
}

bool solve(pt p1, pt p2, pt p3, pt p4)
{
    int o1 = orientation(p1, p2, p3);
    int o2 = orientation(p1, p2, p4);
    int o3 = orientation(p3, p4, p1);
    int o4 = orientation(p3, p4, p2);

    if (o1 != o2 && o3 != o4)
        return true;

    if (!o1 && collinear(p3, p1, p2))
        return true;
    
    if (!o2 && collinear(p4, p1, p2))
        return true;
    
    if (!o3 && collinear(p1, p3, p4))
        return true;
    
    if (!o4 && collinear(p2, p3, p4))
        return true;

    return false;
}

int32_t main()
{
    int n;cin>>n;
    pt p1, p2, p3, p4;

    while (n--)
    {
        read(p1);
        read(p2);
        read(p3);
        read(p4);

        string ans = solve(p1, p2, p3, p4) ? "YES\n" : "NO\n";
        cout << ans;
    }
}
