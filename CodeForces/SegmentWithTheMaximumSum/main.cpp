#include <bits/stdc++.h>

using namespace std;

struct SegTree {

    long long SKIP_VALUE = -1e18;
    int ts;
    vector<long long> ST, sufx, prex;

    SegTree(int tsize) {
        ts = 1;
        while (ts < tsize)
            ts *= 2;
        ST.assign(2 * ts + 2, 0LL);
        sufx.assign(2 * ts + 2, 0LL);
        prex.assign(2 * ts + 2, 0LL);
    }

    long long mergeN(long long n1, long long n2, long long sn1, long long pn2) {
        return max(sn1 + pn2, max(n1, n2));
    }

    void build(int id, int l, int r, long long *a, int n) {
        if (l >= n) {
            ST[id] = SKIP_VALUE;
            sufx[id] = SKIP_VALUE;
            prex[id] = SKIP_VALUE;
            return;
        }
        if (l == r) {
            ST[id] = max(a[l], 0LL);
            sufx[id] = max(a[l], 0LL);
            prex[id] = max(a[l], 0LL);
            return;
        }
        int mid = (l + r) / 2;
        build(id * 2, l, mid, a, n);
        build(id * 2 + 1, mid + 1, r, a, n);
        ST[id] = mergeN(ST[id * 2], ST[id * 2 + 1], sufx[id * 2], prex[id * 2 + 1]);

    }

    void build(long long *a, int n) {
        build(1, 0, ts, a, n);
    }

    void update(int id, int l, int r, int i, int v) {
        if (i < l || r < i) {
            return ;
        }
        if (l == r) {
            ST[id] = max(v, 0LL);
            sufx[id] = max(v, 0LL);
            prex[id] = max(v, 0LL);
            return ;
        }

        int mid = (l + r) / 2;
        update(id * 2, l, mid, i, v);
        update(id * 2 + 1, mid + 1, r, i, v);
        ST[id] = mergeN(ST[id * 2], ST[id * 2 + 1], sufx[id * 2], prex[id * 2 + 1]);
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

long long arr[500005];

int main()
{
    int n, m, a, b;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%lld", &arr[i]);
    SegTree st = SegTree(n);
    st.build(1, 0, n, arr, n);
    printf("%lld\n", st.get(0, n));
    while (m--) {
        scanf("%d %d", &a, &b);
        st.update(a, b);
        printf("%lld\n", st.get(0, n));
    }

    return 0;
}
