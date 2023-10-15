#include <bits/stdc++.h>
using namespace std;

int input[];
int tree[];

void build(int s, int e, int pos)
{
    if (s == e)
    {
        tree[pos] = input[s];
        return;
    }
    int mid = (s + e) / 2;
    // Left child of current leaf
    build(s, mid, pos*2 + 1);
    // Right child of current leaf
    build(mid + 1, s, pos*2 + 2);

    // Gives minimum of parent range, knowing the minimum of the leaf ranges
    tree[pos] = min(tree[pos*2+1], tree[pos*2+2]);

}
int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> input[i];

    memset(tree, 1000000000, sizeof(tree));

    int m;cin >> m;
    while(m--)
    {
        int s, e;
        cin >> s >> e;

        build(s, e, 0);
    }
}