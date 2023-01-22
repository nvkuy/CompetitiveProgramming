#include <bits/stdc++.h>

using namespace std;

struct SegTree {

    long long SKIP_VALUE = 1e18;
    int ts;
    vector<long long> ST;

    SegTree(int tsize) {
        ts = 1;
        while (ts < tsize)
            ts *= 2;
        ST.assign(2 * ts + 2, SKIP_VALUE);
    }

    long long mergeN(long long n1, long long n2) {
        return min(n1, n2);
    }

    void build(int id, int l, int r, vector<long long> &a, int n) {
        if (l >= n) {
            ST[id] = SKIP_VALUE;
            return;
        }
        if (l == r) {
            ST[id] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(id * 2, l, mid, a, n);
        build(id * 2 + 1, mid + 1, r, a, n);
        ST[id] = mergeN(ST[id * 2], ST[id * 2 + 1]);
    }

    void build(vector<long long> &a, int n) {
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
        ST[id] = mergeN(ST[id * 2], ST[id * 2 + 1]);
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

int main()
{

    long long n, ans = 0;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int pos = 0;
    while (true) {
        if (pos >= n)
            break;
        int p1 = pos++;
        int p2 = pos, max_h = 0;
        while (pos < n && a[pos] >= a[pos - 1])

    }
    /*
    SegTree st = SegTree(n);
    st.build(a, n);
    for (int i = 1; i + 1 < n; i++) {
        //ans = max(ans, min(a[i] - st.get(0, i - 1), a[i] - st.get(i + 1, n - 1)));

    }
    cout << ans << endl;
    */

    return 0;
}
