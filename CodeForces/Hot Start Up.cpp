#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

// const int MaxSizeST = 12 * 1e5 + 9;
// pair<long long, long long> ST[MaxSizeST];

// void pushDown(int id) {
//     long long lz = ST[id].second;
//     ST[id].second = 0;
//     if (id * 2 + 1 < MaxSizeST)
//         ST[id * 2 + 1] = {ST[id * 2 + 1].first + lz, ST[id * 2 + 1].second + lz};
//     if (id * 2 + 2 < MaxSizeST)
//         ST[id * 2 + 2] = {ST[id * 2 + 2].first + lz, ST[id * 2 + 2].second + lz};
// }

// long long mergeNode(long long n1, long long n2) {
//     return min(n1, n2);
// }

// void build(int id, int l, int r) {
//     if (l == r) {
//         if (l == 0)
//             ST[id] = {0, 0};
//         else
//             ST[id] = {1e18, 0};
//         return;
//     }
//     int m = (l + r) / 2;
//     build(id * 2 + 1, l, m);
//     build(id * 2 + 2, m + 1, r);
//     ST[id] = {mergeNode(ST[id * 2 + 1].first, ST[id * 2 + 2].first), 0};
// }

// long long getLR(int id, int l, int r, int lx, int rx) {
//     if (lx > r || rx < l)
//         return 2e18;
//     if (lx <= l && r <= rx)
//         return ST[id].first;
//     pushDown(id);
//     int m = (l + r) / 2;
//     return mergeNode(getLR(id * 2 + 1, l, m, lx, rx), getLR(id * 2 + 2, m + 1, r, lx, rx));
// }

// void updateLR(int id, int l, int r, int lx, int rx, long long val) {
//     if (lx > r || rx < l)
//         return;
//     if (lx <= l && r <= rx) {
//         ST[id] = {ST[id].first + val, ST[id].second + val};
//         return;
//     }
//     pushDown(id);
//     int m = (l + r) / 2;
//     updateLR(id * 2 + 1, l, m, lx, rx, val);
//     updateLR(id * 2 + 2, m + 1, r, lx, rx, val);
//     ST[id] = {mergeNode(ST[id * 2 + 1].first, ST[id * 2 + 2].first), 0};
// }

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {

        int n, k;
        cin >> n >> k;
        vector<int> a(n + 1), h(k + 1), c(k + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= k; i++) cin >> c[i];
        for (int i = 1; i <= k; i++) cin >> h[i];

        // build(0, 0, k);

        // for (int i = 1; i <= n; i++) {
        //     if (i == 1) {
        //         updateLR(0, 0, k, 0, k, c[a[i]]);
        //         continue;
        //     }
        //     long long pf_ai = getLR(0, 0, k, a[i], a[i]);
        //     long long pf_min = getLR(0, 0, k, 0, k);
        //     updateLR(0, 0, k, 0, k, a[i] == a[i - 1] ? h[a[i]] : c[a[i]]);
        //     long long f_p = getLR(0, 0, k, a[i - 1], a[i - 1]);
        //     updateLR(0, 0, k, a[i - 1], a[i - 1], -f_p);
        //     f_p = min(f_p, pf_ai + h[a[i]]);
        //     f_p = min(f_p, pf_min + c[a[i]]);
        //     updateLR(0, 0, k, a[i - 1], a[i - 1], f_p);
        // }

        // cout << getLR(0, 0, k, 0, k) << endl;

        vector<long long> ps(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            ps[i] = ps[i - 1];
            if (i > 0 && a[i] == a[i - 1])
                ps[i] += h[a[i]];
            else
                ps[i] += c[a[i]];
        }
 
        vector<long long> f(n + 1, 1e18);
        vector<int> pre(k + 1, -1);
        f[0] = 0;
        for (int i = 1; i <= n; i++) {
            f[i] = f[i - 1] + c[a[i]];
            if (pre[a[i]] != -1) {
                if (pre[a[i]] == i - 1)
                    f[i] = f[i - 1] + h[a[i]];
                else {
                    int j = pre[a[i]];
                    f[i] = min(f[i], f[j + 1] + ps[i - 1] - ps[j + 1] + h[a[i]]);
                }
            }
            pre[a[i]] = i;
        }
 
        cout << f[n] << endl;

    }

    return 0;
}