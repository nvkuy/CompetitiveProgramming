#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")


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

    int n, ai, m, a, b, t;
    cin >> n;
    SegTree sto = SegTree(n);
    SegTree ste = SegTree(n);
    for (int i = 0; i < n; i++) {
        cin >> ai;
        if (i % 2)
            sto.update(i, ai);
        else
            ste.update(i, ai);
    }
    cin >> m;
    while (m--) {
        cin >> t >> a >> b;
        if (t == 0) {
            a--;
            if (a % 2)
                sto.update(a, b);
            else
                ste.update(a, b);
        } else {
            a--, b--;
            if (a % 2)
                cout << sto.get(a, b) - ste.get(a, b) << endl;
            else
                cout << ste.get(a, b) - sto.get(a, b) << endl;
        }
    }

    return 0;
}
