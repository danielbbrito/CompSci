#include <bits/stdc++.h>
using namespace std;

int V = 6;
int E = 3;

vector< pair< int, pair<int,int> > > EdgeList;

class UnionFind {
    private:
    vector<int> p;
    vector<int> rank;

    public:
    UnionFind(int N)
    {
        p.assign(N, 0);
        rank.assign(N,0);

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

    int unionSet(int i, int j)
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

int kruskal(vector< pair< int, pair<int,int> > > EdgeList)
{
    sort(EdgeList.begin(), EdgeList.end());

    int cost = 0;

    UnionFind UF(V);

    // Go through each edge
    for (auto it: EdgeList)
    {
        if (!UF.sameSet(it.second.first, it.second.second))
        {
            cost += it.first;
            UF.unionSet(it.second.first, it.second.second);
        }
    }

    return cost;
}

int main ()
{

}

