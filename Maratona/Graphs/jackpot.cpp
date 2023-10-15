// Kadane's algorithm
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;

    cin >> n;

    while (n)
    {
        vector<int> arr;

        for (int i = 0; i < n; i++)
        {
            int a;cin >> a;
            arr.push_back(a);
        }
        int local = 0;
        int maxg = INT_MIN;

        for (int i = 0; i < (int)arr.size(); i++)
        {
            local = max(arr[i], local + arr[i]);

            if (local > maxg)
                maxg = local;
            
        }

        if (maxg)
            cout << "The maximum winning streak is " << maxg << ".\n";
        
        else
            cout << "Losing streak.\n";
            
        arr.clear();
        cin >> n;
    }


}