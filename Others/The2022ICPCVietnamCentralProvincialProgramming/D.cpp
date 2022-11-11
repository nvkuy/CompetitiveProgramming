#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

inline void debugLocal() {
    if (!fopen("input.txt", "r"))
        return;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

struct SegTree {

    int ts;
    // vector<vector<int>> ST;
    int **ST;

    SegTree(int tsize) {
        ts = 1;
        while (ts < tsize)
            ts *= 2;
        // ST.resize(2 * ts + 2);
        ST = new int * [2 * ts + 2];
    }

    ~SegTree() {
        for (int i = 0; i < 2 * ts + 2; i++)
            delete [] ST[i];
        delete [] ST;
    }

    void mergeN(int id1, int id2, int id3, int n1, int n2) {
        ST[id3] = new int[n1 + n2];
        int i = 0, j = 0, k = 0;
        while (i < n1 || j < n2) {
            int nn1 = 1e5 + 1, nn2 = nn1;
            if (i < n1)
                nn1 = ST[id1][i];
            if (j < n2)
                nn2 = ST[id2][j];
            if (nn1 < nn2) {
                ST[id3][k] = nn1;
                i++;
            } else {
                ST[id3][k]  = nn2;
                j++;
            }
            k++;
        }
    }

    void build(int id, int l, int r, int *a, int n) {
        if (l == r) {
            ST[id] = new int[1];
            if (l < n)
                ST[id][0] = a[l];
            else
                ST[id][0] = 1e5 + 1;
            return;
        }
        int mid = (l + r) / 2;
        build(id * 2, l, mid, a, n);
        build(id * 2 + 1, mid + 1, r, a, n);
        mergeN(id * 2, id * 2 + 1, id, mid - l + 1, r - mid);
    }

    void build(int *a, int n) {
        build(1, 0, ts, a, n);
        // for (int i = 0; i < 8; i++)
        //     cout << ST[1][i] << ' ';
        // cout << endl;
    }

    int get(int id, int l, int r, int u, int v, int k) {
        if (v < l || r < u) {
            return 0;
        }
        if (u <= l && r <= v) {
            int ll = 0, rr = r - l + 1, mm;
            while (ll < rr) {
                mm = (ll + rr) / 2;
                if (ST[id][mm] <= k)
                    ll = mm + 1;
                else
                    rr = mm;
            }
            return rr;
        }
        int mid = (l + r) / 2;
        return get(id * 2, l, mid, u, v, k) + get(id * 2 + 1, mid + 1, r, u, v, k);
    }

    int get(int l, int r, int k) {
        return get(1, 0, ts, l, r, k);
    }

};

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int n, q, l, r;
    cin >> n >> q;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    SegTree st = SegTree(n);
    st.build(a, n);
    delete [] a;
    while (q--) {
        cin >> l >> r;
        l--, r--;
        int ll = 1, rr = 1e5, mm, gt = (r - l + 2) / 2;
        while (ll < rr) {
            mm = (ll + rr) / 2;
            if (st.get(l, r, mm) < gt)
                ll = mm + 1;
            else
                rr = mm;
        }
        cout << rr << endl;
    }

    return 0;
}
