#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const long long MAXN = 100001;
const long long SKIP_VALUE = 0, mod = 1e9 + 7;
struct Node {
    long long lazy = 1;
    long long val = 0;
} nodes[MAXN * 4];

void pushDown(int id) {
    long long t = nodes[id].lazy;
    nodes[id * 2].lazy = (nodes[id * 2].lazy * t) % mod;
    nodes[id * 2].val = (nodes[id * 2].val * t) % mod;

    nodes[id * 2 + 1].lazy = (nodes[id * 2 + 1].lazy * t) % mod;
    nodes[id * 2 + 1].val = (nodes[id * 2 + 1].val * t) % mod;

    nodes[id].lazy = 1;
}

void build(int id, int l, int r) {
    if (l == r) {
        nodes[id].val = 1;
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    nodes[id].val = nodes[id * 2].val + nodes[id * 2 + 1].val;
}

void update(int id, int l, int r, int u, int v, long long val) {
    if (v < l || r < u)
        return ;
    if (u <= l && r <= v) {
        nodes[id].val = (val * nodes[id].val) % mod;
        nodes[id].lazy = (val * nodes[id].lazy) % mod;
        return ;
    }
    int mid = (l + r) / 2;

    pushDown(id);
    update(id * 2, l, mid, u, v, val);
    update(id * 2 + 1, mid + 1, r, u, v, val);

    nodes[id].val = (nodes[id * 2].val + nodes[id * 2 + 1].val) % mod;
}

long long get(int id, int l, int r, int u, int v) {
    if (v < l || r < u)
        return SKIP_VALUE;
    if (u <= l && r <= v)
        return nodes[id].val;
    int mid = (l + r) / 2;
    pushDown(id);
    return (get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v)) % mod;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long n, m, a, b, c, t;
    cin >> n >> m;
    build(1, 1, n);
    while (m--) {
        cin >> t;
        if (t == 1) {
            cin >> a >> b >> c;
            update(1, 1, n, a + 1, b, c);
        } else {
            cin >> a >> b;
            cout << get(1, 1, n, a + 1, b) << endl;
        }
    }

    return 0;
}
