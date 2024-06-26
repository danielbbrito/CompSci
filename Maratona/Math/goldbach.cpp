#include <bits/stdc++.h>

using namespace std;

vector<int> sieve(int n)
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
    vector<int> primes = sieve(1000000);
    while (n)
    {
        
        for (int i = 0; i < primes.size(); i++)
        {
            int lookup = n - primes[i];
            if (binary_search(primes.begin() + i, primes.end(), lookup))
            {
                cout << n << " = " << primes[i] << " + " << lookup << endl;
                break;
            }

        }
        cin >> n;
    }

    return 0;
}