#include <bits/stdc++.h>

using namespace std;

#define MAX 1000000
vector<int> primes;

void sieve(int n)
{
    bool marked[n] = {true};

    for (int i = 0; i <= (n - 1) / 2; i++)
    {
        for (int j = i; j <= (n - 1) / 2; j++)
        {
            marked[i+j+2*i*j] = false;
        }
    }

    primes.push_back(2);

    for (int i = 1; i < n; i++)
        if (2*i + 1 < n)
            primes.push_back(2*i+1);
}

bool binarySearch(int s, int e, int target)
{
    if (e <= s)
        return false;
    
    int m = (s + e) / 2;

    if (primes[m] == target)
        return true;
    
    if (primes[m] > target)
        return binarySearch(s, m - 1, target);
    
    else
        return binarySearch(m + 1, e, target);
}
void findPrimes(int n)
{
    if (n < 4 || n % 2 != 0)
    {
        cout << "Goldbach's conjecture is wrong.\n";
        return;
    }

    sieve(n);

    for (auto it: primes)
    {
        if (binarySearch(0, primes.size() - 1, n - it))
        {
            cout << n << " = " << it << " + " << n - it << endl;
            return;
        }
    }

    
}

int main()
{
    int n;

    cin >> n;

    while (n)
    {
        findPrimes(n);
        primes.clear();
        cin >> n;
    }
}