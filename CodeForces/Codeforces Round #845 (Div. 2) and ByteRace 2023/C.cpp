#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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
            ST[id] += v;
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

vector<vector<int>> has;
vector<int> a;
int m, n;

bool check(int diff) {
    SegTree cnt = SegTree(m + 1);
    vector<int> ttt(m + 1, 0);
    cnt.build(ttt, m + 1);
    int j = 0;
    for (int i = 0; i < n; i++) {
        for (int tmp : has[i])
            cnt.update(tmp, 1);
        while (a[i] - a[j] > diff) {
            for (int tmp : has[j])
                cnt.update(tmp, -1);
            j++;
        }
        if (a[i] < m)
            continue;
        if (cnt.get(1, m) > 0) {
            // cout << "Diff = " << diff << " OK WITH " << j << " TO " << i << endl;
            return true;
        }
    }
    return false;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        set<int> tttt;
        for (int i = 0; i < n; i++) {
            int ai;
            cin >> ai;
            tttt.insert(ai);
        }
        n = tttt.size();
        a.clear();
        has.clear();
        has.resize(n);
        for (int ai : tttt)
            a.push_back(ai);
        for (int i = 0; i < n; i++) {
            for (int j = 1; j * j <= a[i]; j++) {
                if (a[i] % j == 0 && j <= m) {
                    has[i].push_back(j);
                    int tmp = a[i] / j;
                    if (tmp != j && tmp <= m)
                        has[i].push_back(tmp);
                }
            }
        }
        int ll = 0, rr = 1e5 + 1, mm;
        while (ll < rr) {
            mm = (ll + rr) / 2;
            if (check(mm))
                rr = mm;
            else
                ll = mm + 1;
        }
        int ans = -1;
        if (check(rr))
            ans = rr;
        cout << ans << endl;
    }

    return 0;
}
