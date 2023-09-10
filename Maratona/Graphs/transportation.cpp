#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;

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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>> t;

    for (int i = 1; i<=t; i++)
    {
        int n,r;cin>>n>>r;

        while (n--)
        {

        }
    }
}