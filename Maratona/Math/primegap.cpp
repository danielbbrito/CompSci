#include <bits/stdc++.h>
using namespace std;

vector<int> SieveOfEratosthenes(int n)
{
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
 
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    
    vector<int> primes;
    for (int p = 2; p <= n; p++)
        if (prime[p])
            primes.push_back(p);
            
    return primes;
}

int main()
{
    int n;
    cin >> n;
    
    vector<int> primes = SieveOfEratosthenes(1299709);
    while (n != 0)
    {
        bool flag = true;   
        for (int i = 0; i < primes.size() && flag; i++)
        {
            if (primes[i] > n && primes[i-1] < n)
            {
                cout << primes[i] - primes[i-1] << endl;
                flag = false;
            }
        }
        
       if (flag)
            cout << 0 << endl;
        cin >> n;
    }
    
    return 0;
}