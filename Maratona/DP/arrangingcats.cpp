#include <bits/stdc++.h>
using namespace std;


int32_t main()
{
    int t;cin>>t;
    
    while (t--)
    {
        int n;cin>>n;
        
        int different[n];
        bool box1[n];
        bool box2[n];
        
        bool equal = true;
        
        for (int i = 0; i < n; i++)
        {
            different[i] = 0;
            char a;
            cin >> a;
            box1[i] = a - 48;
        }
        
        for (int i = 0; i < n; i++)
        {
            char a;
            cin>>a;
            box2[i] = a - 48;
            if (box2[i] != box1[i])
            {
                equal = false;
                
                if (box2[i])
                {
                    different[i] = 2;
                }
                else
                {
                    different[i] = 1;
                }
            }
        }
        if (equal)
        {
            cout << 0 << endl;
            continue;
        }
        
        int days = 0;
        
        for (int i = 0; i < n; i++)
        {
            if (different[i] == 1)
            {
                bool flag = false;
                days++;
                for (int j = i + 1; j < n; j++)
                {
                    if (different[j] == 2)
                    {
                        flag = true;
                        box2[i] = 1;
                        box2[j] = 0;
                        
                        different[i] = 0;
                        different[j] = 0;
                    }
                }

                if (!flag)
                {
                    box2[i] = 1;
                    different[i] = 0;
                }
            }
            
            if (different[i] == 2)
            {
                bool flag = false;
                days++;
                for (int j = i + 1; j < n; j++)
                {
                    if (different[j] == 1)
                    {
                        flag = true;
                        box2[i] = 0;
                        box2[i] = 1;
                        different[i] = 0;
                        different[j] = 0;
                    }
                }
                
                if (!flag)
                {
                    box2[i] = 0;
                    different[i] = 0;
                }
            }
        }
        
        
        cout << days << endl;
    }
    
    
}