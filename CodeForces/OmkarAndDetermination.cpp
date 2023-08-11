#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int MAXN = 1e6;
int SegTree[4 * MAXN + 1], n, m;
vector<vector<int>> f;

int mergeNode(int n1, int n2) {
    return max(n1, n2);
}

void build(int id, int lx, int rx) {
    if (lx > m) return;
    if (lx == rx) {
        for (int i = 1; i <= n; i++)
            SegTree[id] = mergeNode(SegTree[id], f[i][lx]);
        return;
    }
    int mx = (lx + rx) / 2;
    build(id * 2 + 1, lx, mx);
    build(id * 2 + 2, mx + 1, rx);
    SegTree[id] = mergeNode(SegTree[id * 2 + 1], SegTree[id * 2 + 2]);
}

int get(int id, int lx, int rx, int ll, int rr) {
    if (lx > rr || rx < ll) return 0;
    if (ll <= lx && rx <= rr) return SegTree[id];
    int mx = (lx + rx) / 2;
    return mergeNode(get(id * 2 + 1, lx, mx, ll, rr), get(id * 2 + 2, mx + 1, rx, ll, rr));
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    f.assign(n + 1, vector<int>(m + 1, 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            f[i][j] = j;
            if (i >= 2 && a[i - 2][j - 1] == '.')
                f[i][j] = min(f[i - 1][j], f[i][j]);
            if (j >= 2 && a[i - 1][j - 2] == '.')
                f[i][j] = min(f[i][j - 1], f[i][j]);
            if (i == 1)
                f[i][j] = 1;
        }
    }

    build(0, 0, m);

    int q;
    cin >> q;
    while (q--) {
        int x1, x2;
        cin >> x1 >> x2;
        cout << (get(0, 0, m, x1, x2) <= x1 ? "YES" : "NO") << endl; 
    }

    return 0;
}
