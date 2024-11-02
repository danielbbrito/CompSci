#include <iostream>

using namespace std;

int bs(int l, int r, int target, int arr[])
{
    if (l > r)
        return -1;

    int mid = (l + r) / 2;

    if (target < arr[mid])
        return bs(l, mid - 1, target, arr);

    if (target > arr[mid])
        return bs(mid + 1, r, target, arr);

    return mid;
}

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
    for (int i = 1; i < n + 1; i++)
    {
        if (bs(1, i, prefix[i] - x, prefix) != -1)
            ans++;
    }

    cout << ans << endl;
    return 0;
}