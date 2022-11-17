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

    vector<int> SKIP_VALUE;
    int ts;
    vector<vector<int>> ST;

    SegTree(int tsize) {
        ts = 1;
        while (ts < tsize)
            ts *= 2;
        ST.assign(2 * ts + 2, SKIP_VALUE);
    }

    void mergeN(vector<int> &v1, vector<int> &v2, vector<int> &ans) {
        ans.resize(v1.size() + v2.size());
        int i = 0, j = 0, k = 0;
        while (i < v1.size() || j < v2.size()) {
            int n1 = 1e5 + 1, n2 = n1;
            if (i < v1.size())
                n1 = v1[i];
            if (j < v2.size())
                n2 = v2[j];
            if (n1 < n2) {
                ans[k] = n1;
                i++;
            } else {
                ans[k] = n2;
                j++;
            }
            k++;
        }
    }

    void build(int id, int l, int r, vector<int> &a, int n) {
        if (l >= n) {
            ST[id] = SKIP_VALUE;
            return;
        }
        if (l == r) {
            ST[id].push_back(a[l]);
            return;
        }
        int mid = (l + r) / 2;
        build(id * 2, l, mid, a, n);
        build(id * 2 + 1, mid + 1, r, a, n);
        mergeN(ST[id * 2], ST[id * 2 + 1], ST[id]);
    }

    void build(vector<int> &a, int n) {
        build(1, 0, ts, a, n);
    }

    int get(int id, int l, int r, int u, int v, int k) {
        if (v < l || r < u) {
            return 0;
        }
        if (u <= l && r <= v) {
            int p = upper_bound(ST[id].begin(), ST[id].end(), k) - ST[id].begin();
            return p;
        }
        int mid = (l + r) / 2;
        return get(id * 2, l, mid, u, v, k) + get(id * 2 + 1, mid + 1, r, u, v, k);
    }

    int get(int l, int r, int k) {
        return get(1, 0, ts, l, r, k);
    }

};

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int n, q, l, r;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    SegTree st = SegTree(n);
    st.build(a, n);
    while (q--) {
        cin >> l >> r;
        l--, r--;
        int ll = 1, rr = 1e5, mm, gt = (r - l + 2) / 2;
        while (ll < rr) {
            mm = (ll + rr) / 2;
            if (st.get(l, r, mm) < gt)
                ll = mm + 1;
            else
                rr = mm;
        }
        cout << rr << endl;
    }

    return 0;
}
