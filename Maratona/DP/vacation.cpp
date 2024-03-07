#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> activities;

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int a;cin>>a;
            activities[i].push_back(a);
        }
    }

}