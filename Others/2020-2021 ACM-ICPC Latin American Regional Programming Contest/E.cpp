#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'

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

int n;

int findL(SegTree &st, int pos, int val) {
    int l = 0, r = pos, m;
    while (l < r) {
        m = (l + r) / 2;
        if (st.get(m, pos) == val)
            r = m;
        else
            l = m + 1;
    }
    return r;
}

int findR(SegTree &st, int pos, int val) {
    int l = pos, r = n - 1, m;
    while (l < r) {
        m = (l + r + 1) / 2;
        if (st.get(pos, m) == val)
            l = m;
        else
            r = m - 1;
    }
    return l;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    vector<int> a(n), ans(n + 1, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<pair<int, int>> max_ranges(n);
    stack<int> s;
    for (int i = 0; i < n; i++) {
        while (true) {
            if (s.size() == 0 || a[s.top()] >= a[i])
                break;
            s.pop();
        }
        int l = 0;
        if (s.size() > 0) l = s.top() + 1;
        max_ranges[i].first = l;
        s.push(i);
    }
    while (s.size() > 0) s.pop();
    for (int i = n - 1; i >= 0; i--) {
        while (true) {
            if (s.size() == 0 || a[s.top()] >= a[i])
                break;
            s.pop();
        }
        int r = n - 1;
        if (s.size() > 0) r = s.top() - 1;
        max_ranges[i].second = r;
        s.push(i);
    }
    
    // SegTree st = SegTree(n);
    // st.build(a, n);
    for (int i = 0; i < n; i++) {
        // int l = findL(st, i, a[i]);
        // int r = findR(st, i, a[i]);
        int l = max_ranges[i].first, r = max_ranges[i].second;
        int rl = l, rr = r;
        if (l != 0)
            rl = i - ((i - l) / 2);
        if (r != n - 1)
            rr = i + ((r - i) / 2);
        if (rl != i) {
            ans[rl]++;
            ans[i]--;
        }
        if (rr != i) {
            ans[i + 1]++;
            ans[rr + 1]--;
        }
    }
    for (int i = 1; i < n; i++)
        ans[i] += ans[i - 1];
    for (int i = 0; i < n; i++)
        cout << ans[i] << ' ';
    cout << endl;

    return 0;
}
