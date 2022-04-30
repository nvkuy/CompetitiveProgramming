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
        return max(n1, n2);
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

    int get(int id, int l, int r, int x) {
        if (l == r)
            return l;
        int mid = (l + r) / 2;
        if (ST[id * 2] >= x)
            return get(id * 2, l, mid, x);
        if (ST[id * 2 + 1] >= x)
            return get(id * 2 + 1, mid + 1, r, x);
        return -1;
    }

    int get(int x) {
        return get(1, 0, ts, x);
    }

};

int arr[100001];

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, t, a, b;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    SegTree st = SegTree(n);
    st.build(arr, n);

    while (m--) {
        cin >> t;
        if (t == 1) {
            cin >> a >> b;
            st.update(a, b);
        } else {
            cin >> a;
            cout << st.get(a) << endl;
        }
    }

    return 0;
}
