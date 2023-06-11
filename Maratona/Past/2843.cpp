#include <bits/stdc++.h>

using namespace std;

typedef struct competidor {
    int react;
    int time;
    int fase = 1;
    int index;
}
comp;

int main()
{
    int n;
    cin >> n;

    comp info[n];

    for (int i = 0; i < n; i++)
    {
        cin >> info[i].react >> info[i].time;
        info[i].index = i;
    }

    deque<comp> rounds;

    for (int i = 0; i < n; i++)
        rounds.push_back(info[i]);
    
    cin.ignore();
    string s;
    cin >> s;
    
    int sz = s.length();
    while (rounds.size())
    {
        int a = rounds[0].react + rounds[0].time * sz;
        int b = rounds[1].react + rounds[1].time * sz;

        if (a < b)
        {
            rounds[0].fase++;
            rounds.push_back(rounds[0])
        }
    }
}