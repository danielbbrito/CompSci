#include <bits/stdc++.h>

using namespace std;

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

    int unionSet(int i, int j)
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
int main()
{

}