#include <bits/stdc++.h>

using namespace std;
vector<string> beverages;
map<string, vector<string >> adjlist;
priority_queue<string> src;
vector<string> order;
void findNodes()
{
    bool flag = false;

    for (auto beverage: beverages)
    {
        for (auto it: adjlist)
        {
            if (it.first != beverage)
            {
                for (auto compare: it.second)
                {
                    if (compare == beverage)
                    {
                        flag = true;
                        break;
                    }
                }
            }

            if (flag) break;
        }

        if (!flag) src.push(beverage);
    }
}

void kahn()
{
    while (src.size())
    {
        string curr = src.top(); src.pop();
        order.push_back(curr);

        for (int i = 0; i < adjlist[curr].size(); i++)
        {
            string fs = adjlist[curr].front();
            adjlist[curr].erase(adjlist[curr].begin());
            bool flag = false;
            for (auto itr: adjlist)
            {
                for (auto second: itr.second)
                {
                    if (second == fs)
                    {
                        flag = true;
                        break;
                    }

                    if (flag) break;
                }
            }

            if (!flag)
            {
                src.push(fs);
            }
        }
    }
}
int main()
{
    int i = 1;
    int n;
    while (cin >> n)
    {
        while (n--)
        {
            string s;
            cin >> s;
            beverages.push_back(s);
        }

        int m;
        cin >> m;

        while (m--)
        {
            string a, b;
            cin >> a >> b;

            adjlist[a].push_back(b);
        }

        cout << "Case #" << i << ":" << " Dilbert should drink beverages in this order:";

        if (adjlist.empty())
        {
            for (auto it: beverages)
                cout << " " << it;
            cout << endl;
        }

        else
        {
            for (auto it: order)
                cout << " " << it;
            cout << endl;
        }
        i++;
        adjlist.clear();
        beverages.clear();
        order.clear();
    }
}