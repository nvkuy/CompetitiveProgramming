#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

inline void debugLocal() {
    if (!fopen("input.txt", "r"))
        return;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

struct SegTree {

    int SKIP_VALUE = -1e9;
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
        if (l > r) return 0;
        return get(1, 0, ts, l, r);
    }

};

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), f(n + 1, 0);
        vector<pair<int, int>> tf(n + 1, {0, n});
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = n - 1; i >= 0; i--) {
            if (i + a[i] + 1 > n) {
                f[i] = -1e9;
                tf[i] = {0, i};
            } else {
                f[i] = f[i + a[i] + 1] + 1;
                tf[i] = {tf[i + a[i] + 1].first + 1, tf[i + a[i] + 1].second};
            }
        }
        // for (int i = 0; i <= n; i++) cout << tf[i].first << ' ';
        // cout << endl;
        SegTree st_suff_max = SegTree(n + 1);
        st_suff_max.build(f, n + 1);
        for (int i = 0; i + 1 < n; i++) {
            if (a[i] == f[i + 1]) {
                cout << 0 << ' ';
                continue;
            }
            if (a[i] == 1 || f[i + 1] >= 0) {
                cout << 1 << ' ';
                continue;
            }
            if (tf[i + 1].first >= a[i] - 1) {
                cout << 1 << ' ';
                continue;
            }
            if (st_suff_max.get(i + 1, n) >= a[i] - 1) {
                cout << 1 << ' ';
                continue;
            }
            if (tf[i + 1].first + st_suff_max.get(tf[i + 1].second + 1, n) >= a[i] - 1) {
                cout << 1 << ' ';
                continue;
            }
            cout << 2 << ' ';
        }
        cout << endl;
    }

    return 0;
}
