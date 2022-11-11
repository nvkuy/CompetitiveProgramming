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

vector<vector<long long>> f;

struct SegTree {

    vector<long long> SKIP_VALUE;;
    int ts;
    vector<vector<long long>> ST;

    SegTree(int tsize) {
        ts = 1;
        while (ts < tsize)
            ts *= 2;
        ST.assign(2 * ts + 2, SKIP_VALUE);
    }

    void mergeN(int id, int l, int r, int n) {
        for (int i = 1; i <= r - l + 1; i++) {
            for (int j = l; j <= r; j++) {
                int k = j + i - 1;
                if (k <= min(r, n - 1))
                    ST[id].push_back(f[j][k]);
            }
        }
        // sort(ST[id].begin(), ST[id].end());
        // cout << l << "->" << r << ": ";
        // for (int i = 0; i < ST[id].size(); i++)
        //     cout << ST[id][i] << ' ';
        // cout << endl;
    }

    void build(int id, int l, int r, int n) {
        if (l >= n) {
            ST[id] = SKIP_VALUE;
            return;
        }
        if (l == r) {
            ST[id].push_back(0);
            return;
        }
        int mid = (l + r) / 2;
        build(id * 2, l, mid, n);
        build(id * 2 + 1, mid + 1, r, n);
        mergeN(id, l, r, n);
    }

    void build(int n) {
        build(1, 0, ts, n);
    }

    int get(int id, int l, int r, int u, int v, long long k) {
        if (v < l || r < u) {
            return 0;
        }
        if (u <= l && r <= v) {
            int pos = upper_bound(ST[id].begin(), ST[id].end(), k) - ST[id].begin();
            return pos;
        }
        int mid = (l + r) / 2;
        return get(id * 2, l, mid, u, v, k) + get(id * 2 + 1, mid + 1, r, u, v, k);
    }

    int get(int l, int r, long long k) {
        return get(1, 0, ts, l, r, k);
    }

};


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int n, q, l, r;
    long long k;
    cin >> n;
    vector<int> a(n);
    f.assign(n, vector<long long>(n, 0));
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int len = 1; len <= n; len++) {
        for (int i = 0; i < n; i++) {
            int j = i + len - 1;
            if (j >= n)
                break;
            f[i][j] += abs(a[i] - a[j]);
            if (i != j) {
                f[i][j] -= f[i + 1][j - 1];
                f[i][j] += (f[i + 1][j] + f[i][j - 1]);
            }
        }
    }
    SegTree st = SegTree(n);
    st.build(n);
    cin >> q;
    while (q--) {
        cin >> l >> r >> k;
        l--, r--;
        cout << st.get(l, r, k) << endl;
    }

    return 0;
}
