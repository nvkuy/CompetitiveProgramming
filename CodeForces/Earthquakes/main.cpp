#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

struct Node {
    int minVal, maxVal, numBD;
    Node (int miv, int mav, int nBD) {
        minVal = miv;
        maxVal = mav;
        numBD = nBD;
    }
};

struct SegTree {

    Node SKIP_VALUE = Node(1e9 + 7, 1e9 + 7, 0);
    int ts;
    vector<Node> ST;

    SegTree(int tsize) {
        ts = 1;
        while (ts < tsize)
            ts *= 2;
        ST.assign(2 * ts + 2, SKIP_VALUE);
    }

    Node mergeN(Node n1, Node n2) {
        return Node(min(n1.minVal, n2.minVal), max(n1.maxVal, n2.maxVal), n1.numBD + n2.numBD);
    }

    void update(int id, int l, int r, int i, int v) {
        if (i < l || r < i)
            return ;
        if (l == r) {
            bool emptyBefore = (ST[id].numBD == 0);
            ST[id] = Node(v, v, emptyBefore);
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

    int get(int id, int l, int r, int u, int v, int p) {
        if (v < l || r < u || ST[id].minVal > p || ST[id].numBD <= 0)
            return 0;
        if (u <= l && r <= v && ST[id].maxVal <= p)
            return ST[id].numBD;
        int mid = (l + r) / 2;
        return get(id * 2, l, mid, u, v, p) + get(id * 2 + 1, mid + 1, r, u, v, p);
    }

    int get(int l, int r, int p) {
        return get(1, 0, ts, l, r, p);
    }

};

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, a, b, c, n, m;
    cin >> n >> m;
    SegTree st = SegTree(n);
    while (m--) {
        cin >> t;
        if (t == 1) {
            cin >> a >> b;
            st.update(a, b);
        } else {
            cin >> a >> b >> c;
            cout << st.get(a, b - 1, c) << endl;
        }
    }

    return 0;
}
