#include <bits/stdc++.h>
using namespace std;

#define read(p) cin >> p.x >> p.y

struct func {
    double a, b, c;
};

struct pt {
    int x, y;
};

void derive(func &f, pt p1, pt p2)
{
   f.a =  (double)(p2.y - p1.y);
   f.b = (double)(p1.x - p2.x);
   f.c = (double)(p1.y * (p2.x - p1.x) - (p2.y - p1.y) * p1.x);
}

double determinant(func f1, func f2)
{
     return f2.b * f1.a - f2.a * f1.b;
}
bool solve(func f1, func f2, pt p1, pt p2)
{
    double det = determinant(f1, f2);

    if (!det)
    {
        if (f1.a == f2.a && f1.b == f2.b && f1.c == f2.c)
            return true;
            
        return false;
    }

    // Cramer's rule
    double x = abs((f1.c * f2.b - f2.c * f1.b) / det);
    double y = abs((f1.a * f2.c - f2.a * f1.c) / det);

    if (x >= min(p1.x, p2.x) && x <= max(p1.x, p2.x))
        if (y >= min(p2.y, p1.y) && y <= max(p2.y, p1.y))
            return true;

    return false;
}

int main()
{
    int n;cin>>n;
    pt p1, p2, p3, p4;

    while (n--)
    {
        read(p1);
        read(p2);
        read(p3);
        read(p4);

        func f1, f2;
        derive(f1, p1, p2);
        derive(f2, p3, p4);

        if (solve(f1, f2, p1, p2))
            cout << "YES\n";

        else
            cout << "NO\n";
    }
}