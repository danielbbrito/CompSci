#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

int m, n;
vector<pair<int, ii>> edgelist;

class UnionFind {
    private:
        vi p;
        vi rank;
    
    public:
    UnionFind(int N)
    {
        p.assign(N, 0);
        rank.assign(N, 0);
        for (int i = 0; i < N;i++)
        {
            p[i] = i;
        }
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

int kruskal()
{
    sort(edgelist.begin(), edgelist.end());

    UnionFind UF(m);

    int cost = 0;

    for (auto it: edgelist)
    {
        if (!UF.sameSet(it.second.first, it.second.second))
        {
            cost += it.first;
            UF.unionSet(it.second.first, it.second.second);
        }
    }

    return cost;
}

int main()
{
    scanf("%d %d", &m, &n);

    while (m && n)
    {
        int total = 0;

        for (int i = 0; i < n; i++)
        {
            int u, v, w;

            scanf("%d %d %d", &u, &v, &w);
            total += w;
            edgelist.push_back({w, {u, v}});
        }

        int k = kruskal();

        printf("%d\n", total - k);
        edgelist.clear();
        scanf("%d %d", &m, &n);
    }

    return 0;
}