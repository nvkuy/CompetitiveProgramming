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

struct Node
{
    long long sumN, xorN, fN;
    Node(long long s, long long x) {
        sumN = s;
        xorN = x;
        fN = sumN - xorN;
    }
};

struct SegTree {

    Node SKIP_VALUE = Node(0, 0);
    int ts;
    vector<Node> ST;

    SegTree(int tsize) {
        ts = 1;
        while (ts < tsize)
            ts *= 2;
        ST.assign(2 * ts + 2, SKIP_VALUE);
    }

    Node mergeN(Node n1, Node n2) {
        return Node(n1.sumN + n2.sumN, n1.xorN ^ n2.xorN);
    }

    void build(int id, int l, int r, vector<int> &a, int n) {
        if (l >= n) {
            ST[id] = SKIP_VALUE;
            return;
        }
        if (l == r) {
            ST[id] = Node(a[l], a[l]);
            return;
        }
        int mid = (l + r) / 2;
        build(id * 2, l, mid, a, n);
        build(id * 2 + 1, mid + 1, r, a, n);
        ST[id] = mergeN(ST[id * 2], ST[id * 2 + 1]);
    }

    void build(vector<int> &a, int n) {
        build(1, 0, ts, a, n);
    }

    Node get(int id, int l, int r, int u, int v) {
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
        return get(1, 0, ts, l, r).fN;
    }

};


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int t;
    cin >> t;
    while (t--) {
        int n, q, l, r;
        cin >> n >> q;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        SegTree st = SegTree(n);
        st.build(a, n);
        while (q--) {
            cin >> l >> r;
            l--, r--;
            int lans = 0, rans = n - 1;
            long long fx = st.get(lans, rans);
            for (int i = 0; i < n; i++) {
                int ll = i, rr = n - 1, mm;
                if (st.get(i, n - 1) != fx)
                    continue;
                while (ll < rr) {
                    mm = (ll + rr) / 2;
                    if (st.get(i, mm) != fx)
                        ll = mm + 1;
                    else
                        rr = mm;
                }
                if (rr - i < rans - lans)
                    lans = i, rans = rr;
            }
            cout << lans + 1 << ' ' << rans + 1 << endl;
        }
    }

    return 0;
}
