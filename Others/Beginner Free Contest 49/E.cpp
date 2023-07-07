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

    int SKIP_VALUE = 1e9 + 7;
    int ts;
    vector<int> ST;

    SegTree(int tsize) {
        ts = 1;
        while (ts < tsize)
            ts *= 2;
        ST.assign(2 * ts + 2, SKIP_VALUE);
    }

    int mergeN(int n1, int n2) {
        return min(n1, n2);
    }

    void build(int id, int l, int r, vector<int> &a, int n) {
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

    void build(vector<int> &a, int n) {
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

struct query {
    int id, l, r, ans;
    query(int idx, int lx, int rx) {
        id = idx, l = lx, r = rx;
        ans = 1e9 + 7;
    }
};

bool cmp(query q1, query q2) {
    return q1.l < q2.l;
}

bool cmp_id(query q1, query q2) {
    return q1.id < q2.id;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    map<int, int> pos;
    vector<int> b(n, 1e9 + 7);
    for (int i = n - 1; i >= 0; i--) {
        if (pos.find(a[i]) != pos.end())
            b[i] = pos[a[i]];
        pos[a[i]] = i;
    }
    // for (int i = 0; i < n; i++)
    //     cout << b[i] << ' ';
    // cout << endl;
    vector<query> querys;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        querys.push_back(query(i, l - 1, r - 1));
    }
    SegTree st = SegTree(n + 1);
    sort(querys.begin(), querys.end(), cmp);
    int j = q - 1;
    for (int i = n - 1; i >= 0; i--) {
        if (b[i] < 1e9)
            st.update(b[i], b[i] - i);
        while (j >= 0 && querys[j].l == i) {
            querys[j].ans = st.get(querys[j].l, querys[j].r);
            j--;
        }
    }
    sort(querys.begin(), querys.end(), cmp_id);
    for (auto q : querys) {
        if (q.ans < 1e9)
            cout << q.ans << endl;
        else
            cout << -1 << endl;
    }

    return 0;
}
