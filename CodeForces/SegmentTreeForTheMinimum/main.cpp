#include <bits/stdc++.h>

using namespace std;

int ST[400004], arr[100001];

void build(int id, int l, int r, int *a, int n) {
    if (l >= n) {
        ST[id] = 1e9 + 7;
        return;
    }
    if (l == r) {
        ST[id] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid, a, n);
    build(id * 2 + 1, mid + 1, r, a, n);
    ST[id] = min(ST[id * 2], ST[id * 2 + 1]);
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
    update(id*2, l, mid, i, v);
    update(id*2 + 1, mid+1, r, i, v);

    ST[id] = min(ST[id*2], ST[id*2 + 1]);
}

int get(int id, int l, int r, int u, int v) {
    if (v < l || r < u) {
        return 1e9 + 7;
    }
    if (u <= l && r <= v) {
        return ST[id];
    }
    int mid = (l + r) / 2;
    return min(get(id*2, l, mid, u, v), get(id*2 + 1, mid+1, r, u, v));
}

int main()
{
    int n, m, t, a, b;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        //update(1, 0, 4 * n, i, a);
    }
    build(1, 0, n, arr, n);
    while (m--) {
        cin >> t >> a >> b;
        if (t == 1)
            update(1, 0, n, a, b);
        else
            cout << get(1, 0, n, a, b - 1) << '\n';
    }

    return 0;
}
