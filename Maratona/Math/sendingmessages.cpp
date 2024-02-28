    #include <bits/stdc++.h>
     
    using namespace std;
    #define int long long
    int32_t main()
    {
        int t;cin>>t;
        while (t--)
        {
            int n,f,a,b;cin>>n>>f>>a>>b;
     
            int moments[n + 1] = {0};
     
            for (int i = 1; i <= n; i++)
            {
                cin>>moments[i];
            }
     
            int total = f;
            int flag = true;
            for (int i = 1; i <= n && flag; i++)
            {
                int gasto = min(a * (moments[i] - moments[i-1]), b);
     
                total -= gasto;
                if (total <= 0)
                    flag = false;
            }
     
            if (flag)
                cout << "yes\n";
     
            else cout << "no\n";
        }
    }