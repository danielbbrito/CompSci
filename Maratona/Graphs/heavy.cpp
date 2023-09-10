#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
int n, m;
vector<pair<int, ii>> EdgeList;

class UnionFind {
    private:
    vector<int> parents;
    vector<int> rank;

    public:

    UnionFind(int N)
    {
        rank.assign(N, 0);
        parents.assign(N, 0);

        for (int i = 0; i < N; i++)
        {
            parents[i] = i;
        }
    }

    int findSet(int i)
    {
        return (parents[i] == i) ? i : findSet(parents[i]);
    }

    int sameSet(int i, int j)
    {
        return findSet(i) == findSet(j);
    }

    void unionSet(int i, int j)
    {
        if (!sameSet(i, j))
        {
            int y = findSet(i), x = findSet(j);

            if (rank[y] > rank[x])
            {
                parents[x] = y;
            }

            else
            {
                parents[y] = x;

                if (rank[y] == rank[x])
                    rank[x]++;
            }
        }
    }
};

vector<int> kruskal()
{
    sort(EdgeList.begin(), EdgeList.end());

    UnionFind UF(n);
    vector<int> weights;
    for (auto it: EdgeList)
    {
        if (!UF.sameSet(it.second.first, it.second.second))
        {
            UF.unionSet(it.second.first, it.second.second);
        }

        else
        {  
            weights.push_back(it.first);
        }
    }

    return weights;
}

int main()
{
    scanf("%d %d", &n, &m);
    while (n || m)
    {
        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);

            EdgeList.push_back({w, {u, v}});
        }

        vector<int> w = kruskal();

        if (w.empty())
            printf("forest");
        else
        {
            sort(w.begin(), w.end());

            printf("%d", w.front());

            for (int i = 1; i < w.size(); i++)
                printf(" %d", w[i]);
        }
        printf("\n");

        EdgeList.clear();

        scanf("%d %d", &n, &m);
    }

    return 0;
}