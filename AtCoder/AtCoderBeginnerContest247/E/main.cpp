#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

struct node {
    int minVal, maxVal;
    long long f_lr;
    node(int miv, int mav, int flr) {
        minVal = miv;
        maxVal = mav;
        f_lr = flr;
    }
};

struct SegTree {

    node SKIP_VALUE = node(1e9, 0, 0);
    int ts, x, y;
    vector<node> ST;

    SegTree(int tsize, int xx, int yy) {
        x = xx, y = yy;
        ts = 1;
        while (ts < tsize)
            ts *= 2;
        ST.assign(2 * ts + 2, SKIP_VALUE);
    }

    node mergeN(node n1, node n2) {
        long long tmp = n1.f_lr + n2.f_lr;
        int miv = min(n2.minVal, n1.minVal), mav = max(n2.maxVal, n1.maxVal);
        if (miv == x && mav == y)
            tmp++;
        return node(miv, mav, tmp);
    }

    void build(int id, int l, int r, int *a, int n) {
        if (l >= n) {
            ST[id] = SKIP_VALUE;
            return;
        }
        if (l == r) {
            ST[id] = node(a[l], a[l], 0);
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

    long long get() {
        /*
        for (int i = 0; i < ST.size(); i++)
            cout << ST[i].f_lr << ' ';
        cout << endl;
        */
        return ST[1].f_lr;
    }

};

int arr[200002];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, x, y;
    cin >> n >> x >> y;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    SegTree st = SegTree(n, y, x);
    st.build(arr, n);
    cout << st.get();

    return 0;
}
