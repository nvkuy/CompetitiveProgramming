#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<long long, int> p1, pair<long long, int> p2) {
    if (p1.first == p2.first)
        return p1.second < p2.second;
    return p1.first < p2.first;
}

struct SegTree {

    long long SKIP_VALUE = -1e18 - 12;
    int ts;
    vector<long long> ST;

    SegTree(int tsize) {
        ts = 1;
        while (ts < tsize)
            ts *= 2;
        ST.assign(2 * ts + 2, SKIP_VALUE);
    }

    long long mergeN(long long n1, long long n2) {
        return max(n1, n2);
    }

    void build(int id, int l, int r, vector<long long> &a) {
        if (l >= a.size()) {
            ST[id] = SKIP_VALUE;
            return;
        }
        if (l == r) {
            ST[id] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(id * 2, l, mid, a);
        build(id * 2 + 1, mid + 1, r, a);
        ST[id] = mergeN(ST[id * 2], ST[id * 2 + 1]);
    }

    void build(vector<long long> &a) {
        build(1, 1, ts, a);
    }

    int get(int id, int l, int r, long long x) {
        int mid = (l + r) / 2;
        if (l == r)
            return l;
        if (ST[id * 2] < x)
            return get(id * 2 + 1, mid + 1, r, x);
        else
            return get(id * 2, l, mid, x);
    }

    int get(long long x) {
        return get(1, 1, ts, x);
    }

    long long getMax() {
        return ST[1];
    }
    void debug() {
        for (int i = 1; i <= 10; i++)
            cout << get(i) << ' ';
        cout << endl;
    }

};

int main() {

    long long t, n, m, x;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<long long> a(n + 1), ps(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            ps[i] = ps[i - 1] + a[i];
        }

        SegTree st = SegTree(n + 1);
        st.build(ps);
        // st.debug();

        while (m--) {
            cin >> x;
            if (x > st.getMax() && ps[n] <= 0) {
                cout << -1 << ' ';
                continue;
            }
            if (x <= st.getMax()) {
                int p = st.get(x);
                cout << p - 1 << ' ';
                continue;
            }
            // long long t1 = x / ps[n];
            // long long t2 = t1 * n - 1LL;
            // x -= (t1 * ps[n]);
            // if (x > 0) {
            //     int p = st.get(x);
            //     t2 += p;
            // }
            // cout << t2 << ' ';
            long long t1 = x - st.getMax();
            long long t2 = t1 / ps[n];
            long long ans = st.get(st.getMax()) - 1 + t2 * n;
            if (t1 % ps[n] > 0)
                ans += n;
            cout << ans << ' ';
        }
        cout << endl;
    }

    return 0;
}