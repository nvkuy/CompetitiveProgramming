#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

struct SegTree {

    bool SKIP_VALUE = true;
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

    void update(int id, int l, int r, int i, bool v) {
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

    bool get(int id, int l, int r, int u, int v) {
        if (v < l || r < u) {
            return SKIP_VALUE;
        }
        if (u <= l && r <= v) {
            return ST[id];
        }
        int mid = (l + r) / 2;
        return mergeN(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
    }

    bool get(int l, int r) {
        return get(1, 0, ts, l, r);
    }

};

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, q, a, b, c, d, t;
    cin >> n >> q;
    vector<int> verCnt(n, 0), horCnt(n, 0);
    SegTree stHor = SegTree(n), stVer = SegTree(n);
    while (q--) {
        cin >> t;
        if (t == 1) {
            cin >> a >> b;
            a--, b--;
            stVer.update(a, true);
            stHor.update(b, true);
            verCnt[a]++, horCnt[b]++;
        } else if (t == 2) {
            cin >> a >> b;
            a--, b--;
            if (verCnt[a] == 1)
                stVer.update(a, false);
            if (horCnt[b] == 1)
                stHor.update(b, false);
            verCnt[a]--, horCnt[b]--;
        } else {
            cin >> a >> b >> c >> d;
            a--, b--, c--, d--;
            cout << ((stVer.get(a, c) | stHor.get(b, d)) ? "Yes" : "No") << endl;
        }
    }

    return 0;
}
