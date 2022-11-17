#include <bits/stdc++.h>
using namespace std;

const int max_size = 8 * 1e5 + 8;
long long seg_tree[max_size];

long long get(int id, int l, int r, int lx, int rx) {
    // cout << id << ' ' << l << ' ' << r << ' ' << seg_tree[id] << ' ' << lx << ' ' << rx << endl;
    if (rx < l || lx > r)
        return 0LL;
    if (l >= lx && rx >= r) {
        // cout << id << ' ' << l << ' ' << r << ' ' << seg_tree[id] << ' ' << lx << ' ' << rx << endl;
        // cout << id << " is inside" << endl;
        return seg_tree[id];
    }
    int m = (l + r) / 2;
    return max(get(id * 2 + 1, l, m, lx, rx), get(id * 2 + 2, m + 1, r, lx, rx));
}

void upd(int id, int l, int r, int pos, long long val) {
    if (r < pos || l > pos)
        return;
    if (l == r) {
        seg_tree[id] = val;
        return;
    }
    int m = (l + r) / 2;
    upd(id * 2 + 1, l, m, pos, val);
    upd(id * 2 + 2, m + 1, r, pos, val);
    seg_tree[id] = max(seg_tree[id * 2 + 1], seg_tree[id * 2 + 2]);
}

int main() {

    memset(seg_tree, 0, sizeof(seg_tree));

    long long n, ans = 0;
    cin >> n;
    vector<long long> h(n), a(n);
    for (int i = 0; i < n; i++) cin >> h[i];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        long long tmp = get(0, 0, n, 0, h[i]) + a[i];
        ans = max(ans, tmp);    
        upd(0, 0, n, h[i], tmp);
        // cout << i << ' ' << tmp << endl;
    }
    cout << ans << endl;
    // for (int i = 0; i < n; i++)
    //     cout << get(0, 0, n, h[i], h[i]) << endl;

    return 0;
}