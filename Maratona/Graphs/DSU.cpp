#include <bits/stdc++.h>

using namespace std;

class DSU {
    private:
        vector<int> parents;
    public:
        DSU(int n) // n is the amount of elements in the DSU, elements should range [1, n]
        {
            parents.assign(n + 1, 0);

            // Initialize all sets, each set has only one element, which is the representative
            for (int i = 1; i <= n; i++)
                parents[i] = i;
        }

        int find_set(int n) // Finds the representative of the set in which n is located
        {
            return parents[n] == n ? n : parents[n] = find_set(parents[n]); // parents[n] = find_set(parents[n]) implements path compression, study more on what it actually does, but it seems pretty clear
        }

        void make_set(int n)
        {
            parents[n] = n; // Set the parent of n to itself since it is the only element in the set currently
        }

        bool same_set(int a, int b)
        {
            return find_set(a) == find_set(b);
        }

        void union_set(int a, int b)
        {
            // Simple, unoptimized union set operation
            int parent_a = find_set(a);
            int parent_b = find_set(b);

            if (parent_a != parent_b)
                parents[a] = parents[b];
        }
};