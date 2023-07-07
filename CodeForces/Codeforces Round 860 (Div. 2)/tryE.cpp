#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

inline void debugLocal() {
    if (!fopen("input.txt", "r"))
        return;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<vector<int>> f(n + 1, vector<int>(2, 0));
        int pre_max = 0;
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = n - 1; i >= 0; i--) {
            if (i + a[i] + 1 > n) {
                f[i][0] = -1e9;
                f[i][1] = pre_max + 1;
            } else {
                f[i][0] = f[i + a[i] + 1][0] + 1;
                f[i][1] = max(f[i + a[i] + 1][1], pre_max) + 1;
            }
            pre_max = max(f[i][0], pre_max);
        }
        for (int i = 0; i + 1 < n; i++) {
            if (a[i] == f[i + 1][0]) {
                cout << 0 << ' ';
                continue;
            }
            if (f[i + 1][0] >= 0 || f[i + 1][1] >= a[i]) {
                cout << 1 << ' ';
                continue;
            }
            cout << 2 << ' ';
        }
        cout << endl;
    }

    return 0;
}
