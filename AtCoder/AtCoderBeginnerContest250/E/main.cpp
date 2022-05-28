#include <bits/stdc++.h>

using namespace std;

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
        return max(n1, n2);
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

    int n, q, r1, r2;
    cin >> n;
    vector<int> a(n), b(n);
    map<int, int> pos1, pos2;
    map<int, int>::iterator it;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (pos1.find(a[i]) == pos1.end())
            pos1.insert(make_pair(a[i], i));
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        if (pos2.find(b[i]) == pos2.end())
            pos2.insert(make_pair(b[i], i));
    }
    SegTree st1 = SegTree(n);
    SegTree st2 = SegTree(n);
    for (int i = 0; i < n; i++) {
        it = pos2.find(a[i]);
        if (it == pos2.end())
            st1.update(i, n);
        else
            st1.update(i, (*it).second);
    }
    for (int i = 0; i < n; i++) {
        it = pos1.find(b[i]);
        if (it == pos1.end())
            st2.update(i, n);
        else
            st2.update(i, (*it).second);
    }
    cin >> q;
    while (q--) {
        cin >> r1 >> r2;
        bool iok = true;
        if (st1.get(0, r1 - 1) >= r2)
            iok = false;
        if (st2.get(0, r2 - 1) >= r1)
            iok = false;
        cout << (iok ? "Yes" : "No") << endl;
    }

    return 0;
}
