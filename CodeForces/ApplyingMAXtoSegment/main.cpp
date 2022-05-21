#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int MAXN = 100001;
const int SKIP_VALUE = 0;
struct Node {
    int lazy;
    int val;
} nodes[MAXN * 4];

void pushDown(int id) {
    int t = nodes[id].lazy;
    nodes[id * 2].lazy = max(t, nodes[id * 2].lazy);
    nodes[id * 2].val = max(t, nodes[id * 2].val);

    nodes[id * 2 + 1].lazy = max(t, nodes[id * 2 + 1].lazy);
    nodes[id * 2 + 1].val = max(t, nodes[id * 2 + 1].val);

}

void update(int id, int l, int r, int u, int v, int val) {
    if (v < l || r < u || nodes[id].lazy >= val)
        return ;
    if (u <= l && r <= v) {
        nodes[id].val = max(val, nodes[id].val);
        nodes[id].lazy = max(val, nodes[id].lazy);
        return ;
    }
    int mid = (l + r) / 2;

    pushDown(id);
    update(id * 2, l, mid, u, v, val);
    update(id * 2 + 1, mid + 1, r, u, v, val);

    nodes[id].val = max(nodes[id * 2].val, nodes[id * 2 + 1].val);
}

int get(int id, int l, int r, int u, int v) {
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

    int n, m, a, b, c, t;
    cin >> n >> m;
    while (m--) {
        cin >> t;
        if (t == 1) {
            cin >> a >> b >> c;
            update(1, 1, n, a + 1, b, c);
        } else {
            cin >> a;
            cout << get(1, 1, n, a + 1, a + 1) << endl;
        }
    }

    return 0;
}
