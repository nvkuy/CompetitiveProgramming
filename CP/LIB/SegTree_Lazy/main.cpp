#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val, lazy;
    Node(int dat, int lzy) {
        val = dat;
        lazy = lzy;
    }
};

struct SegTree {

    Node SKIP_VALUE = Node(0, 0);
    int ts;
    vector<Node> ST;

    SegTree(int tsize) {
        ts = 1;
        while (ts < tsize)
            ts *= 2;
        ST.assign(2 * ts + 2, SKIP_VALUE);
    }

    Node mergeN(Node n1, Node n2) {
        return Node(max(n1.val, n2.val), 0);
    }

    void pushDown(int id) {
        int lz = ST[id].lazy;
        ST[id * 2].val += lz;
        ST[id * 2].lazy += lz;
        ST[id * 2 + 1].val += lz;
        ST[id * 2 + 1].lazy += lz;
        ST[id].lazy = 0;
    }

    void build(int id, int l, int r, vector<int> &a, int n) {
        if (l >= n) {
            ST[id] = SKIP_VALUE;
            return;
        }
        if (l == r) {
            ST[id] = Node(a[l], 0);
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

    void update(int id, int l, int r, int u, int v, int val) {
        if (v < l || r < u) {
            return;
        }
        if (u <= l && r <= v) {
            ST[id].val += val;
            ST[id].lazy += val;
            return ;
        }
        pushDown(id);
        int mid = (l + r) / 2;
        update(id * 2, l, mid, u, v, val);
        update(id * 2 + 1, mid + 1, r, u, v, val);
        ST[id] = mergeN(ST[id * 2], ST[id * 2 + 1]);
    }

    void update(int l, int r, int val) {
        update(1, 0, ts, l, r, val);
    }

    Node get(int id, int l, int r, int u, int v) {
        if (v < l || r < u) {
            return SKIP_VALUE;
        }
        if (u <= l && r <= v) {
            return ST[id];
        }
        pushDown(id);
        int mid = (l + r) / 2;
        return mergeN(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
    }

    int get(int l, int r) {
        Node rs = get(1, 0, ts, l, r);
        return rs.val;
    }

};

//Note: LazySegTree index 0

int main()
{
    int n, m, t, x, y, k;
    cin >> n >> m;
    vector<int> arr(n, 0);
    SegTree ST = SegTree(n);
    ST.build(arr, n);
    while (m--) {
        cin >> t;
        if (t == 0) {
            cin >> x >> y >> k;
            ST.update(x - 1, y - 1, k);
        } else {
            cin >> x >> y;
            cout << ST.get(x - 1, y - 1) << '\n';
        }
    }

    return 0;
}
