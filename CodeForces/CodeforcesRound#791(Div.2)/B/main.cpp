#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int MAXN = 200002;
const long long SKIP_VALUE = 0;
struct Node {
    long long lazy;
    long long val;
} nodes[MAXN * 4];

void pushDown(int id, int l, int r) {
    long long t = nodes[id].lazy;
    int mid = (l + r) / 2;
    if (t == 0)
        return;
    nodes[id * 2].lazy = t;
    nodes[id * 2].val = (long long)(mid - l + 1) * t;

    nodes[id * 2 + 1].lazy = t;
    nodes[id * 2 + 1].val = (long long)(r - mid) * t;

    nodes[id].lazy = 0;
}

void update(int id, int l, int r, int u, int v, long long val) {
    if (v < l || r < u) {
        return ;
    }
    if (u <= l && r <= v) {
        nodes[id].val = val * (long long)(r - l + 1);
        nodes[id].lazy = val;
        return ;
    }
    int mid = (l + r) / 2;

    pushDown(id, l, r);
    update(id * 2, l, mid, u, v, val);
    update(id * 2 + 1, mid + 1, r, u, v, val);

    nodes[id].val = nodes[id * 2].val + nodes[id * 2 + 1].val;
}

long long get(int id, int l, int r, int u, int v) {
    if (v < l || r < u) {
        return SKIP_VALUE;
    }
    if (u <= l && r <= v) {
        return nodes[id].val;
    }
    int mid = (l + r) / 2;
    pushDown(id, l, r);
    return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, q, t;
    long long ai, a, b;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> ai;
        update(1, 1, n, i, i, ai);
    }
    while (q--) {
        cin >> t;
        if (t == 1) {
            cin >> a >> b;
            update(1, 1, n, a, a, b);
        } else {
            cin >> a;
            update(1, 1, n, 1, n, a);
        }
        cout << get(1, 1, n, 1, n) << endl;
    }

    return 0;
}
