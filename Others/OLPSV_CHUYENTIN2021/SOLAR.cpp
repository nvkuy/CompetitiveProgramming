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

struct node {
    int minVal = 1e9, minPos = 1e9;
    long long sumNode = 0;
    node(int m, int p, long long s) {
        minVal = m;
        minPos = p;
        sumNode = s;
    }
};

struct SegTree {

    node SKIP_VALUE = node(1e9, 1e9, 0);
    int ts;
    vector<node> ST;

    SegTree(int tsize) {
        ts = 1;
        while (ts < tsize)
            ts *= 2;
        ST.assign(2 * ts + 2, SKIP_VALUE);
    }

    node mergeN(node n1, node n2) {
        node tmp = n1;
        tmp.sumNode += n2.sumNode;
        if (n1.minVal > n2.minVal)
            tmp.minPos = n2.minPos, tmp.minVal = n2.minVal;
        return tmp;
    }

    void build(int id, int l, int r, vector<int> &a, int n) {
        if (l >= n) {
            ST[id] = SKIP_VALUE;
            return;
        }
        if (l == r) {
            ST[id] = {a[l], l, a[l]};
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

    void update(int id, int l, int r, int i, int v) {
        if (i < l || r < i) {
            return ;
        }
        if (l == r) {
            ST[id] = {v, l, v};
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

    node get(int id, int l, int r, int u, int v) {
        if (v < l || r < u) {
            return SKIP_VALUE;
        }
        if (u <= l && r <= v) {
            return ST[id];
        }
        int mid = (l + r) / 2;
        return mergeN(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
    }

    node get(int l, int r) {
        return get(1, 0, ts, l, r);
    }

};


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int n, q, d, l, r, p, t;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    SegTree st = SegTree(n);
    st.build(a, n);
    long long dd = 0;
    while (q--) {
        cin >> t;
        if (t == 1) {
            cin >> d;
            dd = (long long)(1e6 * n) + dd - d;
        } else if (t == 2) {
            cin >> l >> r >> p;
            l--, r--;
            long long ll = (l + dd) % n;
            long long rr = (r + dd) % n;
            int mp;
            if (ll <= rr) {
                node tmp = st.get(ll, rr);
                mp = tmp.minPos;
            } else {
                node t1 = st.get(0, rr);
                node t2 = st.get(ll, n);
                node tmp = st.mergeN(t2, t1);
                mp = tmp.minPos;
            }
            st.update(mp, p);
        } else {
            cin >> l >> r;
            l--, r--;
            long long ll = (l + dd) % n;
            long long rr = (r + dd) % n;
            node tmp = st.SKIP_VALUE;
            if (ll <= rr) {
                tmp = st.get(ll, rr);
            } else {
                node t1 = st.get(0, rr);
                node t2 = st.get(ll, n);
                tmp = st.mergeN(t2, t1);
            }
            cout << tmp.sumNode << endl;
        }
    }

    return 0;
}
