#include <bits/stdc++.h>

using namespace std;

map<string, set<string>> adjlist;

vector<string> bfs(string s, string e)
{
    bool seen[1500];
    memset(seen, false, sizeof(seen));

    queue<vector<string>> q;

    q.push({s});
    seen[stoi(s)] = true;

    while (q.size())
    {
        vector<string> u = q.front();
        q.pop();

        if (u.back() == e)
            return u;

        for (auto it : adjlist[u.back()])
        {
            if (!seen[stoi(it)])
            {
                vector<string> n = u;
                n.push_back(it);
                q.push(n);
                seen[stoi(it)] = true;
            }
        }
    }

    return {"connection impossible"};
}

int main()
{
    ios_base::sync_with_stdio(false);
    int n;

    while (cin >> n)
    {
        string s;
        cin.ignore();

        while (n--)
        {
            getline(cin, s);

            string num1 = "", num2 = "";

            int j = 0;

            while (s[j] != '-')
            {
                num1 += s[j];
                j++;
            }

            for (int i = j + 1; i < s.length(); i++)
            {
                if (s[i] == ',')
                {
                    adjlist[num1].insert(num2);
                    num2 = "";
                    continue;
                }
                num2 += s[i];
            }
        }

        int m;
        cin >> m;
        cout << "-----\n";
        while (m--)
        {
            string a, b;
            cin >> a >> b;

            vector<string> path = bfs(a, b);

            cout << path.front();

            for (int i = 1; i < path.size(); i++)
                cout << ' ' << path[i];

            cout << endl;
        }
    }

    return 0;
}