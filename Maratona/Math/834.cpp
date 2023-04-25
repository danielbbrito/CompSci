#include <bits/stdc++.h>

using namespace std;

vector<int> nums;
void calculate(int n, int m)
{
    if (!n || !m)
    {
        return;
    }

    nums.push_back(n / m);
    calculate(m, n % m);
}

int main()
{
    int n, m;

    while (cin >> n >> m)
    {
        cout << '[' << n / m;

        calculate(m, n % m);

        if (nums.size())
            cout << ';' << nums.front();

        for (int i = 1; i < nums.size(); i++)
            cout << ',' << nums[i];

        cout << ']' << endl;
        nums.clear();
    }
}