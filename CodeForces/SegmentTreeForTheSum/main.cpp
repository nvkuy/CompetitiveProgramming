#include <bits/stdc++.h>

using namespace std;

long long ST[1000000];

void update(int id, int l, int r, int i, int v) {
    if (i < l || r < i) {
        return ;
    }
    if (l == r) {
        ST[id] = v;
        return ;
    }

    int mid = (l + r) / 2;
    update(id*2, l, mid, i, v);
    update(id*2 + 1, mid+1, r, i, v);

    ST[id] = ST[id*2] + ST[id*2 + 1];
}

long long get(int id, int l, int r, int u, int v) {
    if (v < l || r < u) {
        return 0;
    }
    if (u <= l && r <= v) {
        return ST[id];
    }
    int mid = (l + r) / 2;
    return get(id*2, l, mid, u, v) + get(id*2 + 1, mid+1, r, u, v);
}

int main()
{
    memset(ST, 0LL, sizeof(ST));
    int n, m, t, a, b;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a;
        update(1, 0, 4 * n, i, a);
    }
    while (m--) {
        cin >> t >> a >> b;
        if (t == 1)
            update(1, 0, 4 * n, a, b);
        else
            cout << get(1, 0, 4 * n, a, b - 1) << '\n';
    }

    return 0;
}
