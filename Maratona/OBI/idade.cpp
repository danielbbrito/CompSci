#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, a, b;
    cin >> m>>a>>b;
    int c =  m-a-b;

    int id = max(a, b);
    id = max(id, c);
    cout << id << endl;
    return 0;
}