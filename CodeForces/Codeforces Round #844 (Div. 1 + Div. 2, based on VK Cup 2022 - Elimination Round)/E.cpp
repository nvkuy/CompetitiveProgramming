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
        return n1 + n2;
    }

    void update(int id, int l, int r, int ll, int rr, map<int, int> &dehashFunc) {
        if (rr < l || r < ll) {
            return ;
        }

        if (ll <= l && rr >= r) {
            ST[id] = dehashFunc[r] - dehashFunc[l] + 1;
            return ;
        }
        int mid = (l + r) / 2;
        update(id * 2, l, mid, ll, rr, dehashFunc);
        update(id * 2 + 1, mid + 1, r, ll, rr, dehashFunc);
        ST[id] = mergeN(ST[id * 2], ST[id * 2 + 1]);
    }

    void update(int l, int r, map<int, int> &dehashFunc) {
        update(1, 0, ts, l, r, dehashFunc);
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

void compress(vector<int> &all, map<int, int> &hashFunc, map<int, int> &dehashFunc) {
    sort(all.begin(), all.end());
    int num = 1;
    for (int i = 0; i < all.size(); i++) {
        if (hashFunc[all[i]] == 0) {
            hashFunc[all[i]] = num;
            dehashFunc[num] = all[i];
            num++;
        }
    }
}

int cal(vector<pair<int, int>> seg, map<int, int> &hashFunc, map<int, int> &dehashFunc) {
    SegTree st = SegTree(hashFunc.size() + 1);
    for (auto p : seg) {
        st.update(hashFunc[p.first], hashFunc[p.second], dehashFunc);
    }
    return st.get(0, hashFunc.size());
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        vector<pair<int, int>> seg_1, seg_2;
        vector<int> all;
        int l, r, u, d;
        for (int i = 0; i < n; i++) {
            cin >> u >> l >> d >> r;
            if (u == 1)
                seg_1.push_back({l, r});
            if (d == 2)
                seg_2.push_back({l, r});
            all.push_back(l);
            all.push_back(r);
        }
        map<int, int> hashFunc, dehashFunc;
        compress(all, hashFunc, dehashFunc);
        int ans = cal(seg_1, hashFunc, dehashFunc) + cal(seg_2, hashFunc, dehashFunc);
        cout << ans << endl;
    }

    return 0;
}
