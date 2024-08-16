#include <iostream>

using namespace std;

int main()
{
    int n, x, ans, last;

    cin >> n >> x;
    int arr[n + 1];
    int prefix[n + 1];
    prefix[0] = 0;

    for (int i = 1; i < n + 1; i++)
    {
        cin >> arr[i];
    }

    for (int i = 1; i < n + 1; i++)
    {
        prefix[i] = prefix[i - 1] + arr[i];
    }

    ans = 0;
    last = 1;
    for (int i = 1; i < n + 1; i++)
    {
        if (i >= x)
        {
            for (int j = last; j <= i; j++)
            {
                if (prefix[i] - prefix[j - 1] == x)
                {
                    ans++;
                    last = j;
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}