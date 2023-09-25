#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'
#define bit_cnt(x) __builtin_popcountll(x)

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

struct SegTreeMin {

    int SKIP_VALUE = 1e9 + 7;
    int ts;
    vector<int> ST;

    SegTreeMin(int tsize) {
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

struct SegTreeMax {

    int SKIP_VALUE = 0;
    int ts;
    vector<int> ST;

    SegTreeMax(int tsize) {
        ts = 1;
        while (ts < tsize)
            ts *= 2;
        ST.assign(2 * ts + 2, SKIP_VALUE);
    }

    int mergeN(int n1, int n2) {
        return max(n1, n2);
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

const int inf = 1e9;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), r_max(n), r_min(n), pos(n + 1);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            pos[a[i]] = i;
        }
        stack<int> st_max, st_min;
        for (int i = n - 1; i >= 0; i--) {
            while (st_max.size() > 0 && a[st_max.top()] < a[i])
                st_max.pop();
            while (st_min.size() > 0 && a[st_min.top()] > a[i])
                st_min.pop();
            int max_pos = n, min_pos = n;
            if (st_max.size() > 0) max_pos = st_max.top();
            if (st_min.size() > 0) min_pos = st_min.top();
            max_pos--, min_pos--;
            r_max[i] = max_pos, r_min[i] = min_pos;
            st_max.push(i);
            st_min.push(i);
        }
        SegTreeMax stMax = SegTreeMax(n);
        stMax.build(a, n);
        SegTreeMin stMin = SegTreeMin(n);
        stMin.build(a, n);
        queue<int> q;
        vector<int> dist(n, inf);
        q.push(0);
        dist[0] = 0;
        while (q.size() > 0) {
            int u = q.front(), v;
            q.pop();
            v = pos[stMax.get(u, r_min[u])];
            if (dist[v] == inf) {
                q.push(v);
                dist[v] = dist[u] + 1;
            }
            v = pos[stMin.get(u, r_max[u])];
            if (dist[v] == inf) {
                q.push(v);
                dist[v] = dist[u] + 1;
            }
        }
        cout << dist[n - 1] << endl;
    }

    return 0;
}
