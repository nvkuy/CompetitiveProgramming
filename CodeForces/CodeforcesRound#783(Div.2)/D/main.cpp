#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int MAXN = 500005;
const long long SKIP_VALUE = -1e18;
struct Node {
    long long lf, ls;
    long long fi, slr;
    long long val;
} nodes[MAXN * 4];

int getValue(int l, int r, long long s) {
    if (s == 0)
        return 0;
    if (s > 0)
        return r - l + 1;
    return -r + l - 1;
}

void pushDown(int id, int l, int r) {

    long long t1 = nodes[id].lf;
    long long t2 = nodes[id].ls;

    nodes[id * 2].lf += t1;
    nodes[id * 2].ls += t2;
    nodes[id * 2].slr += t2;
    nodes[id * 2].fi += t1;
    nodes[id * 2].val = nodes[id * 2].fi + nodes[id * 2].slr;

    nodes[id * 2 + 1].lf += t1;
    nodes[id * 2 + 1].ls += t2;
    nodes[id * 2 + 1].slr += t2;
    nodes[id * 2 + 1].fi += t1;
    nodes[id * 2 + 1].val = nodes[id * 2 + 1].fi + nodes[id * 2 + 1].slr;

    nodes[id].lf = nodes[id].ls = 0;
}

void update(int id, int l, int r, int u, int v, long long fi, long long slr) {
    if (v < l || r < u) {
        return ;
    }
    if (u <= l && r <= v) {
        nodes[id].fi += fi;
        nodes[id].slr += slr;
        nodes[id].lf += fi;
        nodes[id].ls += slr;
        nodes[id].val = nodes[id].fi + nodes[id].slr;
        return ;
    }
    int mid = (l + r) / 2;

    pushDown(id);
    update(id * 2, l, mid, u, v, fi, slr);
    update(id * 2 + 1, mid + 1, r, u, v, fi, slr);

    Node tmp = nodes[id * 2];
    if (nodes[id * 2].val < nodes[id * 2 + 1].val)
        tmp = nodes[id * 2 + 1];
    nodes[id] = tmp;
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
    return max(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<long long> a(n + 1), f(n + 1, SKIP_VALUE);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        f[0] = 0;
        f[1] = getValue(1, 1, a[1]);
        update(1, 1, n, 1, 1, f[1], 0);
        for (int i = 2; i <= n; i++) {
            update(1, 1, n, 1, i - 1, 0, a[i]);
            f[i] = get(1, 1, n, 1, i - 1);
            update(1, 1, n, i, i, f[i], 0);
        }
        cout << f[n] << endl;
        cout << "TEST: " << endl;
        for (int i = 1; i <= n; i++)
            cout << f[i] << ' ';
        cout << endl;
    }

    return 0;
}
