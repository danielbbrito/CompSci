#include <bits/stdc++.h>

using namespace std;

int main()
{
    int dist;
    cin >> dist;

    dist -= 5;
    dist = dist % 8;

    cout << dist << endl;
    return 0;
}