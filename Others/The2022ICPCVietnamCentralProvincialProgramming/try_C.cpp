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

    long long SKIP_VALUE = 0;
    int ts;
    vector<long long> ST;

    SegTree(int tsize) {
        ts = 1;
        while (ts < tsize)
            ts *= 2;
        ST.assign(2 * ts + 2, SKIP_VALUE);
    }

    long long mergeN(long long n1, long long n2) {
        return n1 + n2;
    }

    void update(int id, int l, int r, int i, long long v) {
        if (i < l || r < i) {
            return ;
        }
        if (l == r) {
            ST[id] = v;
            return ;
        }

        int mid = (l + r) / 2;
        update(id * 2, l, mid, i, v);
        update(id * 2 + 1, mid + 1, r, i, v);
        ST[id] = mergeN(ST[id * 2], ST[id * 2 + 1]);
    }

    void update(int i, long long v) {
        update(1, 0, ts, i, v);
    }

    long long get(int id, int l, int r, int u, int v) {
        if (v < l || r < u) {
            return SKIP_VALUE;
        }
        if (u <= l && r <= v) {
            return ST[id];
        }
        int mid = (l + r) / 2;
        return mergeN(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
    }

    long long get(int l, int r) {
        return get(1, 0, ts, l, r);
    }

};

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> r(n + 1, {0, 0});
    for (int i = 0; i < n; i++) 
        cin >> r[i].first >> r[i].second;
    sort(r.begin(), r.end());
    SegTree st = SegTree(n + 1);
    vector<long long> pf(n + 1, 0);
    st.update(0, 1);
    for (int i = 1; i <= k; i++) {
        vector<long long> f(n + 1, 0);
        for (int j = 1; j <= n; j++) {
            f[j] = st.get(0, r[j].second);
            // cout << f[j] << ' ';
            st.update(r[j].second, pf[j]);
        }
        // cout << endl;
        pf = f;
        for (int i = 0; i <= n; i++)
            st.update(i, 0);
    }
    long long ans = 0;
    for (int i = 0; i <= n; i++)
        ans += pf[i];
    cout << ans << endl;

    return 0;
}
