#include <bits/stdc++.h>
using namespace std;

int main()
{
    int c;
    cin >> c;

    while (c--)
    {
        int n;
        cin >> n;

        int grades[n];

        for (int i = 0; i < n; i++)
            cin >> grades[i];

        // Calculate average
        float avg = 0;
        for (int i = 0; i < n; i++)
            avg += grades[i];

        avg /= (float)n;

        float pct = 0;

        for (int i = 0; i < n; i++)
            if (grades[i] > avg)
                pct++;

        pct /= (float)n;
        pct *= 100;

        printf("%.3f%%\n", pct);
    }

    return 0;
}