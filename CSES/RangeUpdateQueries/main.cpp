#include <bits/stdc++.h>

using namespace std;

struct SegTree {

    int ts;
    vector<long long> ST;

    SegTree(int tsize) {
        ts = 1;
        while (ts < tsize)
            ts *= 2;
        ST.assign(2 * ts + 2, 0LL);
    }

    void build(int id, int l, int r, int *a, int n) {
        if (l >= n) {
            ST[id] = 0LL;
            return;
        }
        if (l == r) {
            ST[id] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(id * 2, l, mid, a, n);
        build(id * 2 + 1, mid + 1, r, a, n);
        ST[id] = 0LL;
    }

    void build(int *a, int n) {
        build(1, 0, ts, a, n);
    }

    void update(int id, int l, int r, int u, int v, int x) {
        if (v < l || r < u)
            return ;
        if (l >= u && v >= r) {
            ST[id] += x;
            return ;
        }
        int mid = (l + r) / 2;
        update(id * 2, l, mid, u, v, x);
        update(id * 2 + 1, mid + 1, r, u, v, x);
    }

    void update(int l, int r, int v) {
        update(1, 0, ts, l, r, v);
    }

    long long get(int id, int l, int r, int i) {
        if (i < l || r < i)
            return 0LL;
        if (l == r)
            return ST[id];
        int mid = (l + r) / 2;
        return ST[id] + get(id * 2, l, mid, i) + get(id * 2 + 1, mid + 1, r, i);
    }

    long long get(int i) {
        return get(1, 0, ts, i);
    }

};

int main()
{
    int n, q, arr[200002], a, b, u, t;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    SegTree st = SegTree(n);
    st.build(arr, n);
    while (q--) {
        scanf("%d", &t);
        if (t == 1) {
            scanf("%d %d %d", &a, &b, &u);
            st.update(a - 1, b - 1, u);
        } else {
            scanf("%d", &u);
            printf("%lld\n", st.get(u - 1));
        }
    }

    return 0;
}
