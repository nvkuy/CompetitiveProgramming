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

struct Node {
    long long val, lazy;
    Node(long long dat, long long lzy) {
        val = dat;
        lazy = lzy;
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
        return Node(n1.val + n2.val, 0);
    }

    void pushDown(int id) {
        int lz = ST[id].lazy;
        ST[id * 2].val += lz;
        ST[id * 2].lazy += lz;
        ST[id * 2 + 1].val += lz;
        ST[id * 2 + 1].lazy += lz;
        ST[id].lazy = 0;
    }

    void update(int id, int l, int r, int u, int v, int val) {
        if (v < l || r < u) {
            return;
        }
        if (u <= l && r <= v) {
            ST[id].val += val;
            ST[id].lazy += val;
            return ;
        }
        pushDown(id);
        int mid = (l + r) / 2;
        update(id * 2, l, mid, u, v, val);
        update(id * 2 + 1, mid + 1, r, u, v, val);
        ST[id] = mergeN(ST[id * 2], ST[id * 2 + 1]);
    }

    void update(int l, int r, int val) {
        update(1, 0, ts, l, r, val);
    }

    int get(int id, int l, int r, int val) {
        if (l == r) {
            if (ST[id].val < val)
                return 1e9;
            return l;
        }
        pushDown(id);
        int m = (l + r) / 2;
        if (ST[id * 2].val >= val)
            return get(id * 2, l, m, val);
        return get(id * 2 + 1, m + 1, r, val);
    }

};

vector<long long> node_cnt, ans;
vector<vector<int>> c, bonus;
SegTree st;

void dfs_cnt_node(int u, int par) {

    node_cnt[u]++;
    for (int v : c[u]) {
        if (v == par) continue;
        dfs_cnt_node(v, u);
        node_cnt[u] += node_cnt[v];
    }

}

void dfs(int u, int par, long long pre_bonus) {

    long long all = pre_bonus / node_cnt[u], just_me = pre_bonus % node_cnt[u];
    for (long long money : bonus[u]) {
        all += money / node_cnt[u];
        just_me += money % node_cnt[u];
    }
    st.update()

}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    

    return 0;
}
