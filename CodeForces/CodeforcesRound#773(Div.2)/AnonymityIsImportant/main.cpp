#include <bits/stdc++.h>

using namespace std;

struct SegTree {

    int SKIP_VALUE = 0;
    int ts;
    vector<int> ST;

    SegTree(int tsize) {
        ts = 1;
        while (ts < tsize)
            ts *= 2;
        ST.assign(2 * ts + 2, -1);
    }

    int mergeN(int n1, int n2) {
        if (n1 == 1 || n2 == 1)
            return 1;
        return min(n1, n2);
    }

    void update(int id, int l, int r, int li, int ri, int v) {
        if (ri < l || r < li) {
            return ;
        }
        if (l == r) {
            ST[id] = v;
            return ;
        }
        int mid = (l + r) / 2;
        if (ST[id * 2] != 0)
            update(id * 2, l, mid, li, ri, v);
        if (ST[id * 2 + 1] != 0)
            update(id * 2 + 1, mid + 1, r, li, ri, v);
        ST[id] = mergeN(ST[id * 2], ST[id * 2 + 1]);
    }

    void update(int li, int ri, int v) {
        update(1, 0, ts, li, ri, v);
    }

    int get(int id, int l, int r, int i) {
        if (i < l || r < i) {
            return SKIP_VALUE;
        }
        if (l == r || ST[id] == 0) {
            return ST[id];
        }
        int mid = (l + r) / 2;
        if (i <= mid)
            return get(id * 2, l, mid, i);
        return get(id * 2 + 1, mid + 1, r, i);
    }

    int get(int i) {
        return get(1, 0, ts, i);
    }

};

int main()
{
    int n, q, t, l, r, x, rp;
    cin >> n >> q;
    SegTree st = SegTree(n);
    while (q--) {
        cin >> t;
        if (t == 0) {
            cin >> l >> r >> x;
            st.update(l - 1, r - 1, x);
        } else {
            cin >> x;
            rp = st.get(x - 1);
            if (rp == -1)
                cout << "N/A\n";
            else
                cout << ((rp == 1) ? "YES" : "NO") << '\n';
        }
    }

    return 0;
}
