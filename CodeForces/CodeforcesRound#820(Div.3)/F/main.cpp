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

    void build(int id, int l, int r, string &s, int n) {
        if (l >= n) {
            ST[id] = SKIP_VALUE;
            return;
        }
        if (l == r) {
            ST[id] = s[l] - '0';
            return;
        }
        int mid = (l + r) / 2;
        build(id * 2, l, mid, s, n);
        build(id * 2 + 1, mid + 1, r, s, n);
        ST[id] = mergeN(ST[id * 2], ST[id * 2 + 1]);
    }

    void build(string &s, int n) {
        build(1, 0, ts, s, n);
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

bool cmp(pair<int, int> p1, pair<int, int> p2) {
    if (p1.first == p2.first)
        return p1.second < p2.second;
    return p1.first < p2.first;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, w, m, n, mod = 9;
    string s;
    cin >> t;
    while (t--) {
        cin >> s;
        cin >> w >> m;
        n = s.length();
        SegTree st = SegTree(n);
        st.build(s, n);
        vector<vector<int>> rm_pos(mod);
        for (int i = 0; i + w - 1 < n; i++) {
            int rm = (st.get(i, i + w - 1) % mod);
            if (rm_pos[rm].size() < 2)
                rm_pos[rm].push_back(i);
        }
        int l, r, k;
        while (m--) {
            cin >> l >> r >> k;
            l--, r--;
            vector<pair<int, int>> ans;
            int rm = (st.get(l, r) % mod);
            for (int rm1 = 0; rm1 < mod; rm1++) {
                if (rm_pos[rm1].size() == 0)
                    continue;
                for (int rm2 = 0; rm2 < mod; rm2++) {
                    if (rm_pos[rm2].size() == 0)
                        continue;
                    if (rm1 == rm2 && rm_pos[rm2].size() < 2)
                        continue;
                    if (((rm1 * rm) + rm2) % mod == k) {
                        int p1 = rm_pos[rm1][0], p2 = rm_pos[rm2][0];
                        if (rm1 == rm2)
                            p2 = rm_pos[rm2][1];
                        ans.push_back({p1, p2});
                    }
                }
            }
            //cout << "ANS: ";
            sort(ans.begin(), ans.end(), cmp);
            if (ans.size() == 0) {
                cout << -1 << ' ' << -1 << endl;
                continue;
            }
            cout << ans[0].first + 1 << ' ' << ans[0].second + 1 << endl;
        }
    }

    return 0;
}
