#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")


struct SegTree {

    int SKIP_VALUE = 0;
    int ts;
    vector<int> ST;

    SegTree(int tsize) {
        ts = 1;
        while (ts < tsize)
            ts *= 2;
        ST.assign(2 * ts + 2, SKIP_VALUE);
    }

    int mergeN(int n1, int n2) {
        return n1 + n2;
    }

    void build(int id, int l, int r, int n) {
        if (l >= n) {
            ST[id] = SKIP_VALUE;
            return;
        }
        if (l == r) {
            ST[id] = 1;
            return;
        }
        int mid = (l + r) / 2;
        build(id * 2, l, mid, n);
        build(id * 2 + 1, mid + 1, r, n);
        ST[id] = mergeN(ST[id * 2], ST[id * 2 + 1]);
    }

    void build(int n) {
        build(1, 0, ts, n);
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

    int get(int id, int l, int r, int u, int v) {
        if (v < l || r < u) {
            return SKIP_VALUE;
        }
        if (u <= l && r <= v) {
            return ST[id];
        }
        int mid = (l + r) / 2;
        return mergeN(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
    }

    int get(int l, int r) {
        if (r < l)
            return 0;
        return get(1, 0, ts, l, r);
    }

};

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        SegTree st = SegTree(n);
        st.build(n);
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            st.update(a[i] - 1, 0);
            long long curPairBD = 0;
            for (int j = i - 1; j >= 0; j--) {
                if (a[j] < a[i])
                    ans += curPairBD;
                curPairBD += st.get(0, a[j] - 2);
            }
        }
        cout << ans << endl;
    }

    return 0;
}
