#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

struct SegTree {

    int SKIP_VALUE = 0;
    int ts;
    vector<int> ST;

    SegTree(int tsize) {
        ts = 1;
        while (ts < tsize)
            ts *= 2;
        ST.assign(2 * ts + 2, SKIP_VALUE);
    }

    int mergeN(int n1, int n2) {
        return max(n1, n2);
    }

    void build(int id, int l, int r, vector<int> &a, int n) {
        if (l >= n) {
            ST[id] = SKIP_VALUE;
            return;
        }
        if (l == r) {
            ST[id] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(id * 2, l, mid, a, n);
        build(id * 2 + 1, mid + 1, r, a, n);
        ST[id] = mergeN(ST[id * 2], ST[id * 2 + 1]);
    }

    void build(vector<int> &a, int n) {
        build(1, 0, ts, a, n);
    }

    int get(int id, int l, int r, int u, int v) {
        if (v < l || r < u) {
            return SKIP_VALUE;
        }
        if (u <= l && r <= v) {
            return ST[id];
        }
        int mid = (l + r) / 2;
        return mergeN(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
    }

    int get(int l, int r) {
        return get(1, 0, ts, l, r);
    }

};

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, x1, x2, y1, y2, k, q;
    cin >> n >> m;
    vector<int> a(m + 1, 0);
    for (int i = 1; i <= m; i++)
        cin >> a[i];
    SegTree st = SegTree(m + 1);
    st.build(a, m + 1);
    cin >> q;
    while (q--) {
        cin >> x1 >> y1 >> x2 >> y2 >> k;
        bool iok = true;
        int maxUp = (n - x1) / k;
        x1 += maxUp * k;
        if (y1 > y2)
            swap(y1, y2);
        if (st.get(y1, y2) >= x1)
            iok = false;
        if ((y2 - y1) % k != 0)
            iok = false;
        if ((x1 - x2) % k != 0)
            iok = false;
        cout << (iok ? "YES" : "NO") << endl;
    }

    return 0;
}