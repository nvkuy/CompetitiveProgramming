#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

struct matrix {
    long long r1c1, r1c2, r2c1, r2c2;
    matrix(long long a1, long long a2, long long a3, long long a4) {
        r1c1 = a1, r1c2 = a2;
        r2c1 = a3, r2c2 = a4;
    }
};

matrix matmul(matrix m1, matrix m2, long long mod) {
    long long a1, a2, a3, a4;
    a1 = (m1.r1c1 * m2.r1c1 + m1.r1c2 * m2.r2c1) % mod;
    a2 = (m1.r1c1 * m2.r1c2 + m1.r1c2 * m2.r2c2) % mod;
    a3 = (m1.r2c1 * m2.r1c1 + m1.r2c2 * m2.r2c1) % mod;
    a4 = (m1.r2c1 * m2.r1c2 + m1.r2c2 * m2.r2c2) % mod;
    return matrix(a1, a2, a3, a4);
}

struct SegTree {

    matrix SKIP_VALUE = matrix(1, 0, 0, 1);
    long long ts, mod;
    vector<matrix> ST;

    SegTree(long long tsize, long long m) {
        ts = 1, mod = m;
        while (ts < tsize)
            ts *= 2;
        ST.assign(2 * ts + 2, SKIP_VALUE);
    }

    matrix mergeN(matrix n1, matrix n2) {
        return matmul(n1, n2, mod);
    }

    void build(int id, int l, int r, vector<matrix> &a, int n) {
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

    void build(vector<matrix> &a, int n) {
        build(1, 0, ts, a, n);
    }

    matrix get(int id, int l, int r, int u, int v) {
        if (v < l || r < u) {
            return SKIP_VALUE;
        }
        if (u <= l && r <= v) {
            return ST[id];
        }
        int mid = (l + r) / 2;
        return mergeN(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
    }

    matrix get(int l, int r) {
        return get(1, 0, ts, l, r);
    }

};

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long r, n, m, a1, a2, a3, a4, le, ri;
    cin >> r >> n >> m;
    vector<matrix> arr;
    for (int i = 0; i < n; i++) {
        cin >> a1 >> a2 >> a3 >> a4;
        arr.push_back(matrix(a1, a2, a3, a4));
    }
    SegTree st = SegTree(n, r);
    st.build(arr, n);
    while (m--) {
        cin >> le >> ri;
        matrix ans = st.get(le - 1, ri - 1);
        cout << ans.r1c1 << ' ' << ans.r1c2 << endl;
        cout << ans.r2c1 << ' ' << ans.r2c2 << endl;
    }

    return 0;
}
