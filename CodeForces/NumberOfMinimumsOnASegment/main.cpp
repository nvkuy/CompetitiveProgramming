#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> node;

struct SegTree {

    node SKIP_VALUE = make_pair(1e9 + 7, 0);
    int ts;
    vector<node> ST;

    SegTree(int tsize) {
        ts = 1;
        while (ts < tsize)
            ts *= 2;
        ST.assign(2 * ts + 2, SKIP_VALUE);
    }

    node mergeN(node n1, node n2) {
        if (n1.first == n2.first)
            return make_pair(n1.first, n1.second + n2.second);
        else if (n1.first < n2.first)
            return n1;
        else
            return n2;
    }

    void build(int id, int l, int r, int *a, int n) {
        if (l >= n) {
            ST[id] = SKIP_VALUE;
            return;
        }
        if (l == r) {
            ST[id] = make_pair(a[l], 1);
            return;
        }
        int mid = (l + r) / 2;
        build(id * 2, l, mid, a, n);
        build(id * 2 + 1, mid + 1, r, a, n);
        ST[id] = mergeN(ST[id * 2], ST[id * 2 + 1]);
    }

    void build(int *a, int n) {
        build(1, 0, ts, a, n);
    }

    void update(int id, int l, int r, int i, int v) {
        if (i < l || r < i) {
            return ;
        }
        if (l == r) {
            ST[id] = make_pair(v, 1);
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

    node get(int id, int l, int r, int u, int v) {
        if (v < l || r < u) {
            return SKIP_VALUE;
        }
        if (u <= l && r <= v) {
            return ST[id];
        }
        int mid = (l + r) / 2;
        return mergeN(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
    }

    node get(int l, int r) {
        return get(1, 0, ts, l, r);
    }

};


int main()
{
    int n, m, arr[100001], t, a, b;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    SegTree st = SegTree(n);
    st.build(arr, n);
    while (m--) {
        cin >> t >> a >> b;
        if (t == 1)
            st.update(a, b);
        else {
            node ans = st.get(a, b - 1);
            cout << ans.first << ' ' << ans.second << '\n';
        }
    }

    return 0;
}
