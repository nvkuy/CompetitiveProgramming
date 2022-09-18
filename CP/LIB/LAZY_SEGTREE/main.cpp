#include <bits/stdc++.h>

using namespace std;

//segtree update range: init arr_i = 0, query add k to range l->r, query getMax in range l->r
const int MAXN = 50005;
const int SKIP_VALUE = -1e9;
struct Node {
    int lazy;
    int val;
} nodes[MAXN * 4];

void pushDown(int id) {
    int t = nodes[id].lazy;
    nodes[id * 2].lazy += t;
    nodes[id * 2].val += t;

    nodes[id * 2 + 1].lazy += t;
    nodes[id * 2 + 1].val += t;

    nodes[id].lazy = 0;
}

void update(int id, int l, int r, int u, int v, int val) {
    if (v < l || r < u) {
        return ;
    }
    if (u <= l && r <= v) {
        nodes[id].val += val;
        nodes[id].lazy += val;
        return ;
    }
    int mid = (l + r) / 2;

    pushDown(id);
    update(id * 2, l, mid, u, v, val);
    update(id * 2 + 1, mid + 1, r, u, v, val);

    nodes[id].val = max(nodes[id * 2].val, nodes[id * 2 + 1].val);
}

int get(int id, int l, int r, int u, int v) {
    if (v < l || r < u) {
        return SKIP_VALUE;
    }
    if (u <= l && r <= v) {
        return nodes[id].val;
    }
    int mid = (l + r) / 2;
    pushDown(id);
    return max(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}
//seg_tree index start from 1
//add k: l->r
//update(1, 1, n, l, r, k);
//get max: l->r
//get(1, 1, n, l, r)

int main()
{

    int n, m, t, l, r, k;
    cin >> n >> m;
    while (m--) {
        cin >> t;
        if (t == 0) {
            cin >> l >> r >> k;
            update(1, 1, n, l, r, k);
        } else {
            cin >> l >> r;
            cout << get(1, 1, n, l, r) << endl;
        }
    }

    return 0;
}
