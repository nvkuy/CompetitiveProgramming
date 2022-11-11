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

    long long SKIP_VALUE = 0;
    int ts;
    vector<long long> ST;

    SegTree(int tsize) {
        ts = 1;
        while (ts < tsize)
            ts *= 2;
        ST.assign(2 * ts + 2, SKIP_VALUE);
    }

    long long mergeN(long long n1, long long n2) {
        return n1 + n2;
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

vector<vector<int>> c;
vector<int> head, tail;
int cur_time = 0;

void dfs(int u, int par) {
    head[u] = ++cur_time;
    for (int v : c[u]) {
        if (v == par)
            continue;
        dfs(v, u);
    }
    tail[u] = cur_time;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int n, q, a, b, s;
    cin >> n >> q;
    c.resize(n + 1);
    head.resize(n + 1);
    tail.resize(n + 1);

    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        c[a].push_back(b);
        c[b].push_back(a);
    }
    dfs(1, 0);

    vector<int> tmp(n + 1, 0);
    for (int i = 1; i <= n; i++)
        tmp[head[i]] = arr[i];
    SegTree st = SegTree(n + 1);
    st.build(tmp, n + 1);

    while (q--) {
        cin >> a;
        if (a == 1) {
            cin >> s >> b;
            st.update(head[s], b);
        } else {
            cin >> s;
            cout << st.get(head[s], tail[s]) << endl;
        }
    }

    return 0;
}
