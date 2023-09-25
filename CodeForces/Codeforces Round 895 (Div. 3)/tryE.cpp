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

const int MAXN = 1e5;
const int SKIP_VALUE = 0;
struct Node {
    int lazy;
    int val;
} nodes[MAXN * 4 + 12];
int pf_xor[MAXN + 1], a[MAXN + 1], n;
string s;

void build(int id, int l, int r) {
    if (l == r) {
        nodes[id] = {0, 0};
        if (s[l - 1] == '1') nodes[id].val = a[l];
        return;
    }
    int m = (l + r) / 2;
    build(id * 2, l, m);
    build(id * 2 + 1, m + 1, r);
    nodes[id] = {0, nodes[id * 2].val ^ nodes[id * 2 + 1].val};
}

void pushDown(int id, int l, int r) {
    int t = nodes[id].lazy, m = (l + r) / 2;
    if (t == 0) return;
    nodes[id * 2].lazy ^= t;
    nodes[id * 2].val ^= (pf_xor[m] ^ pf_xor[l - 1]);
    nodes[id * 2 + 1].lazy ^= t;
    nodes[id * 2 + 1].val ^= (pf_xor[r] ^ pf_xor[m]);
    nodes[id].lazy = 0;
}

void update(int id, int l, int r, int u, int v) {
    if (v < l || r < u) return;
    if (u <= l && r <= v) {
        nodes[id].lazy ^= 1;
        nodes[id].val ^= (pf_xor[r] ^ pf_xor[l - 1]);
        return;
    }
    int mid = (l + r) / 2;
    pushDown(id, l, r);
    update(id * 2, l, mid, u, v);
    update(id * 2 + 1, mid + 1, r, u, v);
    nodes[id].val = nodes[id * 2].val ^ nodes[id * 2 + 1].val;
}

int get(int id, int l, int r, int u, int v) {
    if (v < l || r < u) {
        return SKIP_VALUE;
    }
    if (u <= l && r <= v) {
        return nodes[id].val;
    }
    int mid = (l + r) / 2;
    pushDown(id, l, r);
    return get(id * 2, l, mid, u, v) ^ get(id * 2 + 1, mid + 1, r, u, v);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            pf_xor[i] = pf_xor[i - 1] ^ a[i];
        }
        cin >> s;
        build(1, 1, n);
        int q;
        cin >> q;
        while (q--) {
            int tp;
            cin >> tp;
            if (tp == 1) {
                int l, r;
                cin >> l >> r;
                update(1, 1, n, l, r);
                continue;
            }
            int b;
            cin >> b;
            int tmp = get(1, 1, n, 1, n);
            cout << (b ? tmp : pf_xor[n] ^ tmp) << ' ';
        }
        cout << endl;
    }

    return 0;
}
