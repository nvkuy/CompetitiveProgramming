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
        return get(1, 0, ts, l, r);
    }

};

int arr[500005];

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, k;
    string s;
    cin >> n >> k >> s;
    vector<bool> del(n, false);
    for (int i = 0; i < n; i++)
        arr[i] = s[i] - '0';
    SegTree st = SegTree(n);
    st.build(arr, n);
    int i = 0;
    while (i < n) {
        if (k <= 0)
            break;
        int val = st.get(i, min(i + k, n - 1));
        //cout << i << '|' << val << endl;
        while (arr[i] != val) {
            del[i] = true;
            i++;
            k--;
        }
        i++;
    }
    for (int i = n - 1; i >= 0; i--) {
        if (k <= 0)
            break;
        if (!del[i]) {
            del[i] = true;
            k--;
        }
    }
    for (int i = 0; i < n; i++) {
        if (!del[i])
            cout << arr[i];
    }

    return 0;
}
