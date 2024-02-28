#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;cin>>t;

    while (t--)
    {
        int n;cin>>n;
        int grid[n][n];
        cin.ignore();
        for (int i = 0; i < n; i++)
        {
            string s;
            getline(cin, s);

            for (int j = 0; j < n; j++)
            {
                grid[i][j] = s[j] - 48;
            }
        }
            
        bool flag = true;
        for (int i = 0; i < n && flag; i++)
            for (int j = 0; j < n && flag; j++)
            {
                // Find first 1
                if (grid[i][j]==1)
                {
                    // Go right and count ones
                    int count = 0;
                    for (int k = j; k < n; k++)
                    {
                        if (grid[i][k] == 1) count++;
                    }

                    if (count == 1)
                        cout << "TRIANGLE\n";
                    
                    else if (grid[i + count - 1][j + count - 1] == 1)
                        cout << "SQUARE\n";
                    
                    else
                        cout << "TRIANGLE\n";
                    
                    flag = false;
                }
            }
    }
}