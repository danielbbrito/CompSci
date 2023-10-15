#include <bits/stdc++.h>

using namespace std;
#define int long long
int currmax;

void solve(const vector<int>& list, int i, int sum)
{
    if (i == list.size())
    {
        if (sum > currmax)
            currmax = sum;
        return;
    }

    solve(list, i + 1, sum);
    solve(list, i + 1, list[i]);
}
int main()
{
    int n;
    cin >> n;

    while (n)
    {
        currmax = INT_MIN;
        vector<int> input;
        for (int i = 0; i < n; i++)
        {
            int a;cin>>a;
            input.push_back(a);
        }

        solve(input, 0, 0);

        cout << currmax << endl;
        cin >> n;
    }
}