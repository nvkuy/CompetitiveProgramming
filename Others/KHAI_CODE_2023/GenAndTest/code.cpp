#include <bits/stdc++.h>

using namespace std;

struct SegTree {

    long long SKIP_VALUE = 0;
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
    
    long long n, q;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    SegTree st = SegTree(n);
    st.build(a, n);
    cin >> q;
    while (q--) {
        int m;
        cin >> m;
        vector<long long> b(m);
        for (int i = 0; i < m; i++) {
            cin >> b[i];
            b[i]--;
        }
        long long ans = 0;
        for (int i = 0; i + 1 < m; i++) {
            if (b[i] + 1 == b[i + 1] || st.get(b[i] + 1, b[i + 1] - 1) < max(a[b[i]], a[b[i + 1]]))
                continue;
            long long num1 = 0, num2 = 0;
            int ll = 0, rr = i, mm;
            while (ll < rr) {
                mm = (ll + rr) / 2;
                if (st.get(b[mm], b[i + 1]) > st.get(b[i], b[i + 1]))
                    ll = mm + 1;
                else
                    rr = mm;
            }
            num1 = i - rr + 1;
            ll = i + 1, rr = m - 1, mm;
            while (ll < rr) {
                mm = (ll + rr + 1) / 2;
                if (st.get(b[i], b[mm]) > st.get(b[i], b[i + 1]))
                    rr = mm - 1;
                else
                    ll = mm;
            }
            num2 = ll - (i + 1) + 1;
            ans += (num1 * num2 * st.get(b[i], b[i + 1]));
        }
        // cout << "@" << ans << endl;
        for (int i = 0; i < m; i++) {
            long long num1 = 0, num2 = 0;
            int ll = 0, rr = i, mm;
            while (ll < rr) {
                mm = (ll + rr) / 2;
                if (st.get(b[mm], b[i]) > a[b[i]])
                    ll = mm + 1;
                else
                    rr = mm;
            }
            num1 = i - rr + 1;
            ll = i, rr = m - 1, mm;
            while (ll < rr) {
                mm = (ll + rr + 1) / 2;
                if (st.get(b[i], b[mm]) > a[b[i]])
                    rr = mm - 1;
                else
                    ll = mm;
            }
            num2 = ll - i + 1;
            ans += (num1 * num2 * a[b[i]]);
            // cout << "@" << b[i] << ' ' << num1 << ' ' << num2 << endl;
        }
        cout << ans << endl;
    }

    return 0;
}
