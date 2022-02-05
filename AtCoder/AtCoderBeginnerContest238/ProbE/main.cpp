#include <bits/stdc++.h>

using namespace std;

struct SegTree {

    int ts;
    vector<bool> ST;

    SegTree(int tsize) {
        ts = 1;
        while (ts < tsize)
            ts *= 2;
        ST.assign(2 * ts + 2, false);
    }

    bool mergeN(bool n1, bool n2) {
        return (n1 & n2);
    }
    void build(int id, int l, int r, int n) {
        if (l >= n) {
            ST[id] = true;
            return;
        }
        int mid = (l + r) / 2;
        //build(id * 2, l, mid, n);
        build(id * 2 + 1, mid + 1, r, n);
        //ST[id] = mergeN(ST[id * 2], ST[id * 2 + 1]);
    }

    void build(int n) {
        build(1, 0, ts, n);
    }
    void update(int id, int l, int r, int u, int v) {
        if (v < l || r < u) {
            return ;
        }
        if (u <= l && v >= r) {
            ST[id] = true;
            return ;
        }
        if (l == r) {
            ST[id] = true;
            return ;
        }
        if (ST[id])
            return ;
        int mid = (l + r) / 2;
        update(id * 2, l, mid, u, v);
        update(id * 2 + 1, mid + 1, r, u, v);
        ST[id] = mergeN(ST[id * 2], ST[id * 2 + 1]);
    }

    void update(int u, int v) {
        update(1, 0, ts, u, v);
    }

    int get(int id, int l, int r, int u, int v) {
        if (v < l || r < u) {
            return true;
        }
        if (ST[id]) {
            return ST[id];
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
    int n, q, l, r;
    cin >> n >> q;
    SegTree st = SegTree(n);
    st.build(n);
    while (q--) {
        cin >> l >> r;
        st.update(l - 1, r - 1);
    }
    cout << (st.get(0, n - 1) ? "Yes" : "No");

    return 0;
}
