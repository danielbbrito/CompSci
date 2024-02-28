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
    int a,b;
    cin >> a >> b;
    
    vector<int> primes = SieveOfEratosthenes(32000);
    while (a||b)
    {
        
        for (int i = 0; primes[i] <= a; i++)
        {
            if (primes[i] >= a)
            {
                vector<int> p;
                for (int j = i+1; primes[j] <= b; j++)
                {
                    if (primes[j] - primes[j-1] == primes[j-1] - primes[j-2])
                    {
                        p.push_back(primes[j-2]);
                        p.push_back(primes[j-1]);
                        p.push_back(primes[j]);
                    }

                }
                if (p.size())
                    cout << p.front();
                
                for (int j = 1; j < p.size(); j++)
                    cout << ' ' << p[j];
                
                i += p.size() - 1;
            }
        }
        
        cin >> a >> b;
    }
    
    return 0;
}