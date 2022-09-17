#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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
 
    long long get(int id, int l, int r, int val) {
        if (l >= val) {
            return SKIP_VALUE;
        }
        if (r < val) {
            return ST[id];
        }
        int mid = (l + r) / 2;
        return mergeN(get(id * 2, l, mid, val), get(id * 2 + 1, mid + 1, r, val));
    }
 
    long long get(int val) {
        return get(1, 0, ts, val);
    }
 
};

long long cal(vector<int> a, int max_val) {
    SegTree st = SegTree(max_val + 1);
    long long ans = 0;
    for (int i = 0; i < a.size(); i++) {
        ans += (i - st.get(a[i] - 1));
        st.update(a[i] - 1, 1);
    }
    return ans;
}

map<int, int> compress(vector<int> a) {
    map<int, int> res;
    int num = 1;
    sort(a.begin(), a.end());
    for (int i = 0; i < a.size(); i++) {
        if (res.find(a[i]) == res.end()) {
            res[a[i]] = num;
            num++;
        }
    }
    return res;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, l;
    cin >> n >> m;
    vector<vector<int>> w(m);
    vector<int> c(n), all_num;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        all_num.push_back(c[i]);
    }
    for (int i = 0; i < m; i++) {
        cin >> l;
        w[i].resize(l);
        for (int j = 0; j < l; j++) {
            cin >> w[i][j];
            all_num.push_back(w[i][j]);
        }
    }
    map<int, int> hf = compress(all_num);
    vector<long long> f(hf.size() + 1, 0);
    for (int i = 0; i < n; i++)
        f[hf[c[i]]]++;
    for (int i = 1; i < f.size(); i++)
        f[i] += f[i - 1];
    long long t1 = cal(c, hf.size());
    for (int i = 0; i < m; i++) {
        long long ans = 1e18, tans = cal(w[i], hf.size()) + t1;
        for (int j = 0; j < w[i].size(); j++)
            tans += (n - f[ hf[w[i][j]] ]);

        //cout << "@"  << tans << endl;       
        ans = min(ans, tans);
        for (int j = 0; j < w[i].size(); j++) {
            tans -= (n - f[ hf[w[i][j]] ]);
            tans += f[hf[w[i][j]] - 1];
            ans = min(ans, tans);

            //cout << "@"  << tans << endl;
        }
        cout << ans << endl;
    }

    return 0;
}