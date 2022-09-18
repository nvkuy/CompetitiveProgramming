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

vector<int> nex, fix;

int getNextFreePos(int pos) {
    if (pos < 0 || fix[pos] == 0)
        return pos;
    if (fix[nex[pos]] == 1)
        nex[pos] = getNextFreePos(nex[pos]);
    return nex[pos];
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, k, a, b, c;
    cin >> n >> k;
    vector<int> ans(n, -1);
    nex.resize(n);
    fix.assign(n, 0);
    for (int i = 0; i < n; i++) {
        nex[i] = i;
        cin >> c;
        if (c == 0)
            continue;
        if (c == 1)
            ans[i] = 1;
        fix[i] = 1;
        nex[i] = getNextFreePos(i - 1);
    }
    SegTree st = SegTree(n);
    st.build(ans, n);
    bool iok = true;
    while (k--) {
        cin >> a >> b >> c;
        a--, b--;
        if (!iok || st.get(a, b) >= c)
            continue;
        int pos = getNextFreePos(b);
        while (true) {
            if (pos < a) {
                iok = false;
                break;
            }
            fix[pos] = 1;
            ans[pos] = 1;
            nex[pos] = getNextFreePos(pos - 1);
            st.update(pos, 1);
            if (st.get(a, b) >= c)
                break;
            pos = nex[pos];
        }
    }
    if (!iok) {
        cout << "Impossible";
        return 0;
    }
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';

    return 0;
}
