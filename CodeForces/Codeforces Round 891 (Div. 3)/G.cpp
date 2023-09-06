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

const long long mod = 998244353;

long long power(long long num, long long pow) {
    if (pow == 0) return 1;
    if (pow % 2) return (num * power(num, pow - 1)) % mod;
    return power((num * num) % mod, pow / 2);
}

struct SegTreeCntLower {

    int SKIP_VALUE = 0;
    int ts;
    vector<int> ST;

    SegTreeCntLower(int tsize = 0) {
        ts = 1;
        while (ts < tsize)
            ts *= 2;
        ST.assign(2 * ts + 2, SKIP_VALUE);
    }

    int mergeN(int n1, int n2) {
        return n1 + n2;
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

struct SegTreeCalHigher {

    int SKIP_VALUE = 1;
    int ts;
    vector<long long> ST;

    SegTreeCalHigher(int tsize = 0) {
        ts = 1;
        while (ts < tsize)
            ts *= 2;
        ST.assign(2 * ts + 2, SKIP_VALUE);
    }

    long long mergeN(long long n1, long long n2) {
        return (n1 * n2) % mod;
    }

    void update(int id, int l, int r, int i, long long v) {
        if (i < l || r < i) {
            return ;
        }
        if (l == r) {
            ST[id] = (ST[id] * v) % mod;
            return ;
        }

        int mid = (l + r) / 2;
        update(id * 2, l, mid, i, v);
        update(id * 2 + 1, mid + 1, r, i, v);
        ST[id] = mergeN(ST[id * 2], ST[id * 2 + 1]);
    }

    void update(int i, long long v) {
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

map<int, int> hashFunc, deHashFunc;
long long ans, s;
vector<vector<pair<int, long long>>> c;
SegTreeCalHigher stHigher;
SegTreeCntLower stLower;

void dfs(int u, int par, int cur_edge = s) {

    //

}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n >> s;
        c.clear();
        c.resize(n + 1);
        hashFunc.clear();
        deHashFunc.clear();
        vector<int> all_num;
        for (int i = 1; i < n; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            c[u].push_back({v, w});
            c[v].push_back({u, w});
            all_num.push_back(w);
        }

        sort(all_num.begin(), all_num.end());
        int max_hash = 0;
        for (int num : all_num) {
            if (hashFunc[num] == 0) {
                max_hash++;
                hashFunc[num] = max_hash;
                deHashFunc[max_hash] = num;
            }
        }

        stHigher = SegTreeCalHigher(max_hash + 2);
        stLower = SegTreeCntLower(max_hash + 2);
        ans = 1;
        dfs(1, 0);

        cout << ans << endl;

    }

    return 0;
}
