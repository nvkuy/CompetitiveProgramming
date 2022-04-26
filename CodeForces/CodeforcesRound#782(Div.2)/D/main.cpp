#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int SKIP_VALUE = 0;
struct Node {
    int lazy;
    long long val;
    Node(int lz, long long va) {
        lazy = lz;
        val = va;
    }
};
vector<Node> nodes;
vector<int> a;

void build(int id, int l, int r, int n) {
    if (l >= n)
        return;
    if (l == r) {
        nodes[id].val = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid, n);
    build(id * 2 + 1, mid + 1, r, n);
    nodes[id].val = nodes[2 * id].val + nodes[2 * id + 1].val;
}

void pushDown(int id) {
    int t = nodes[id].lazy;

    nodes[id * 2].lazy += t;
    nodes[id * 2].val += t;
    nodes[id * 2 + 1].lazy += t;
    nodes[id * 2 + 1].val += t;

    nodes[id].lazy = 0;
}

void update(int id, int l, int r, int u, int v, int val) {
    if (v < l || r < u) {
        return ;
    }
    if (u <= l && r <= v) {
        nodes[id].val += val;
        nodes[id].lazy += val;
        return ;
    }
    int mid = (l + r) / 2;

    pushDown(id);
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
    pushDown(id);
    return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long t, n, s;
    cin >> t;
    while (t--) {
        cin >> n;
        a.resize(n), nodes.assign(4 * n, Node(0, 0));
        vector<bool> ans(n, false);
        s = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            s += a[i];
        }
        build(1, 0, n - 1, n);
        int k = (s / n);
        for (long long i = n - 1; i >= 0; i--) {
            //cout << get(1, 0, n - 1, i, i) << '|' << k << endl;
            int udr = k;
            if (get(1, 0, n - 1, i, i) == (i + 1)) {
                ans[i] = true;
                k--;
            }
            //cout << "UPDATE: " << i - udr + 1 << ' ' << i << endl;
            update(1, 0, n - 1, i - udr + 1, i, -1);
        }
        for (int i = 0; i < n; i++)
            cout << ans[i] << ' ';
        cout << endl;
    }

    return 0;
}
