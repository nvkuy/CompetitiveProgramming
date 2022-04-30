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

    void build(int id, int l, int r, int *a, int n) {
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

    void build(int *a, int n) {
        build(1, 0, ts, a, n);
    }

    void update(int id, int l, int r, int i) {
        if (i < l || r < i) {
            return ;
        }
        if (l == r) {
            ST[id] = 1 - ST[id];
            return ;
        }

        int mid = (l + r) / 2;
        update(id * 2, l, mid, i);
        update(id * 2 + 1, mid + 1, r, i);
        ST[id] = mergeN(ST[id * 2], ST[id * 2 + 1]);
    }

    void update(int i) {
        update(1, 0, ts, i);
    }

    int get(int id, int l, int r, int k) {
        if (l == r)
            return l;
        int mid = (l + r) / 2;
        if (k > ST[id * 2])
            return get(id * 2 + 1, mid + 1, r, k - ST[id * 2]);
        return get(id * 2, l, mid, k);
    }

    int get(int k) {
        return get(1, 0, ts, k);
    }

};

int arr[500005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, a, b;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    SegTree st = SegTree(n);
    st.build(arr, n);

    while (m--) {
        cin >> a >> b;
        if (a == 1)
            st.update(b);
        else
            cout << st.get(b + 1) << endl;
    }

    return 0;
}
