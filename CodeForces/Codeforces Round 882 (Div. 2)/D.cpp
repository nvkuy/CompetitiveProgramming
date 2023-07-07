#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'

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

    void update(int id, int l, int r, int i, int v) {
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

    void update(int i, int v) {
        update(1, 0, ts, i, v);
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

    int n, m, q;
    cin >> n >> m >> q;
    string s;
    cin >> s;
    vector<pair<int, int>> ranges(m);
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        ranges[i] = {l - 1, r - 1};
    }
    
    vector<int> pos(n, -1);
    set<int> avai;
    for (int i = 0; i < n; i++)
        avai.insert(i);

    int cur = 0, cntOne = 0;
    for (auto range : ranges) {
        while (true) {
            auto it = avai.lower_bound(range.first);
            if (it == avai.end() || *it > range.second) break;
            pos[*it] = cur++;
            avai.erase(it);
        }
    }

    SegTree st = SegTree(n);
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') continue;
        cntOne++;
        if (pos[i] != -1)
            st.update(pos[i], 1);
    }

    while (q--) {
        int x;
        cin >> x;
        x--;
        int real_pos = pos[x];
        if (s[x] == '1') {
            s[x] = '0';
            cntOne--;
        } else {
            s[x] = '1';
            cntOne++;
        }
        if (real_pos != -1)
            st.update(real_pos, s[x] - '0');
        int space = min(cur, cntOne);
        cout << space - st.get(0, space - 1) << endl;
    }

    return 0;
}
