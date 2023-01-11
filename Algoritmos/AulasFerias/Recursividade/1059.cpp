#include <bits/stdc++.h>

using namespace std;

void Nums(int n)
{
    if (n == 0)
    {
        return;
    }
    Nums(n - 2);
    cout << n << endl;

}

int main()
{
    Nums(100);
    return 0;
}