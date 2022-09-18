#include <bits/stdc++.h>

using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

long long gcd(long long a, long long b) {
    if (b == 0LL)
        return a;
    return gcd(b, a % b);
}

struct SegTree {

    long long SKIP_VALUE = 0LL;
    int ts;
    vector<long long> ST;

    SegTree(int tsize) {
        ts = 1;
        while (ts < tsize)
            ts *= 2;
        ST.assign(2 * ts + 2, SKIP_VALUE);
    }

    long long mergeN(long long n1, long long n2) {
        return gcd(n1, n2);
    }

    void build(int id, int l, int r, long long *a, int n) {
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

    void build(long long *a, int n) {
        build(1, 0, ts, a, n);
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

long long a[100001];

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, ans = 1e9;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    SegTree ST = SegTree(n);
    ST.build(a, n);
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (ST.get(j, i) != 1LL)
            continue;
        while (ST.get(j, i) == 1LL) {
            ans = min(ans, i - j + 1);
            j++;
        }
    }
    if (ans == 1e9)
        ans = -1;
    cout << ans;

    return 0;
}
