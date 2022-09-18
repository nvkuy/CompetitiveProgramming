#include <bits/stdc++.h>

using namespace std;

struct segstree {

    int ts;
    vector<int> ST;

    segstree(int tsize) {
        ts = 1;
        while (ts < tsize)
            ts *= 2;
        ST.assign(2 * ts, 0);
    }

    int mergeN(int id1, int id2) {
        return min(ST[id1], ST[id2]);
    }

    void build(int id, int l, int r, int *a, int n) {
        if (l >= n) {
            ST[id] = 1e9 + 7;
            return;
        }
        if (l == r) {
            ST[id] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(id * 2, l, mid, a, n);
        build(id * 2 + 1, mid + 1, r, a, n);
        ST[id] = mergeN(id * 2, id * 2 + 1);
        //ST[id] = min(ST[id * 2], ST[id * 2 + 1]);
    }

    void build(int *a, int n) {
        build(1, 0, ts, a, n);
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
        ST[id] = mergeN(id * 2, id * 2 + 1);
        //ST[id] = min(ST[id*2], ST[id*2 + 1]);
    }

    void update(int i, int v) {
        update(1, 0, ts, i, v);
    }

    int get(int id, int l, int r, int u, int v) {
        if (v < l || r < u) {
            return 1e9 + 7;
        }
        if (u <= l && r <= v) {
            return ST[id];
        }
        int mid = (l + r) / 2;
        return min(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
    }

    int get(int l, int r) {
        return get(1, 0, ts, l, r);
    }

};

int main()
{
    int n, q, arr[200002], a, b;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    segstree st = segstree(n);
    st.build(arr, n);
    while (q--) {
        cin >> a >> b;
        cout << st.get(a - 1, b - 1) << endl;
    }

    return 0;
}
