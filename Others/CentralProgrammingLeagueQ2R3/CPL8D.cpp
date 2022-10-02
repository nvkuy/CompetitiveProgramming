#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

inline void debugLocal() {
    if (!fopen("input.txt", "r"))
        return;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

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
        return Node(n1.val + n2.val, 0);
    }

    void pushDown(int id, int l, int r) {
        int lz = ST[id].lazy;
        if (lz == 0)
            return;
        int m = (l + r) / 2;
        if (id * 2 < ST.size()) {
            ST[id * 2].val = m - l + 1;
            ST[id * 2].lazy = m - l + 1;
        }
        if (id * 2 + 1 < ST.size()) {
            ST[id * 2 + 1].val = r - m;
            ST[id * 2 + 1].lazy = r - m;
        }
        ST[id].lazy = 0;
    }

    void update(int id, int l, int r, int u, int v, int val) {
        if (v < l || r < u) {
            return;
        }
        if (u <= l && r <= v) {
            ST[id].val = r - l + 1;
            ST[id].lazy = 1;
            // pushDown(id, l, r);
            return ;
        }
        pushDown(id, l, r);
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
            // pushDown(id, l, r);
            return ST[id];
        }
        pushDown(id, l, r);
        int mid = (l + r) / 2;
        return mergeN(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
    }

    int get(int l, int r) {
        Node rs = get(1, 0, ts, l, r);
        return rs.val;
    }

};

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int t, n, x1, y1, x2, y2, minY = 1000, maxY = 0;
    vector<SegTree> mm(1001, SegTree(1001));
    cin >> n >> t;
    for (int i = 0; i < n; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        for (int j = y1; j <= y2; j++)
            mm[j].update(x1, x2, 1);
        minY = min(minY, y1);
        maxY = max(maxY, y2);
    }
    int s = 0, c = 0;
    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= 1000; j++) {
            if ((mm[i].get(j - 1, j) + mm[i - 1].get(j - 1, j)) == 4)
                s++;
        }
    }
    for (int i = 0; i <= 1000; i++) {
        if (i == 0 || i == 1000 || mm[i - 1].get(0, 1000) == 0 || mm[i + 1].get(0, 1000) == 0) {
            c += mm[i].get(0, 1000);
            if (i < 1000 && mm[i + 1].get(0, 1000) > 0)
                c += min(2, mm[i + 1].get(0, 1000));
        } else
            c += min(2, mm[i].get(0, 1000));
    }
    cout << s << endl;
    if (t == 2)
        cout << c << endl;

    return 0;
}
