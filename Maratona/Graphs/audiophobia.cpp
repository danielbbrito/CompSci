#include <bits/stdc++.h>

using namespace std;
int c, q, s;
vector< pair< int, pair<int,int> > > edgelist;


class UnionFind {
    private:
    vector<int> p;
    vector<int> rank;

    public:
    UnionFind(int N)
    {
        p.assign(N, 0); rank.assign(N, 0);

        for (int i = 0; i < N; i++)
            p[i] = i;
    }

    int findSet(int i)
    {
        return p[i] == i ? i : findSet(p[i]);
    }

    bool sameSet(int i, int j)
    {
        return findSet(i) == findSet(j);
    }

    void unionSet(int i, int j)
    {
        if (!sameSet(i, j))
        {
            int x = findSet(i), y = findSet(j);

            if (rank[x] > rank[y])
                p[y] = x;
            else
            {
                p[x] = y;

                if (rank[y] == rank[x])
                    rank[y]++;
            }
        }
    }
};

int kruskal(int)
int main()
{

    cin >> c >> s >> q;

    while (c || s || q)
    {
        while (s--)
        {
            int u, v, w;
            cin >> u >> v >>w;
            edgelist.push_back({w, {u, v}});
        }

        while (q--)
        {
            int c1,c2;
            cin >> c1 >> c2;

            cout << kruskal() << "\n\n";
        }

        edgelist.clear();
        cin >> c >> s >> q;
    }
}