#include <bits/stdc++.h>
using namespace std;

struct xor_pos {
    set<int> odd, even;
};

int main() {

    int n, q, l, r;
    cin >> n >> q;
    vector<int> a(n + 1), px(n + 1, 0), zr_cnt(n + 1, 0);
    map<int, xor_pos> mm;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        px[i] = px[i - 1] ^ a[i];
        if (i % 2)
            mm[px[i]].odd.insert(i);
        else
            mm[px[i]].even.insert(i);
        zr_cnt[i] = zr_cnt[i - 1];
        if (a[i] == 0)
            zr_cnt[i]++;
    }
    while (q--) {
        cin >> l >> r;
        if ((px[r] ^ px[l - 1]) != 0) {
            cout << -1 << endl;
            continue;
        }
        if (zr_cnt[r] - zr_cnt[l - 1] == r - l + 1) {
            cout << 0 << endl;
            continue;
        }
        if ((r - l + 1) % 2) {
            cout << 1 << endl;
            continue;
        }
        int pos = -1;
        if (l % 2) {
            auto it = mm[px[l - 1]].odd.lower_bound(l);
            if (it != mm[px[l - 1]].odd.end())
                pos = *it;
        } else {
            auto it = mm[px[l - 1]].even.lower_bound(l);
            if (it != mm[px[l - 1]].even.end())
                pos = *it;
        }
        if (pos < 0 || pos > r) {
            cout << -1 << endl;
            continue;
        }
        if (zr_cnt[pos] - zr_cnt[l - 1] == pos - l + 1 || zr_cnt[r] - zr_cnt[pos - 1] == r - pos + 1) {
            cout << 1 << endl;
            continue;
        }
        cout << 2 << endl;
    }

    return 0;
}