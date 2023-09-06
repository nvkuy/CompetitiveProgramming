#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'
#define bit_cnt(x) __builtin_popcountll(x)

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        vector<vector<int>> f(n + 1, vector<int>(2, 1e9));
        for (int i = 1; i <= n; i++) cin >> a[i];
        f[1][1] = 0, f[1][0] = 1;
        for (int i = 2; i <= n; i++) {
            if (a[i] == a[i - 1]) {
                f[i][1] = min(f[i][1], f[i - 1][0]);
                f[i][1] = min(f[i][1], f[i - 1][1] + 1);
                f[i][0] = min(f[i][0], f[i - 1][0] + 1);
            } else if (a[i] > a[i - 1]) {
                f[i][1] = min(f[i][1], f[i - 1][1]);
                f[i][1] = min(f[i][1], f[i - 1][0]);
                f[i][0] = min(f[i][0], f[i - 1][0] + 1);
            } else {
                f[i][1] = min(f[i][1], f[i - 1][1] + 1);
                f[i][1] = min(f[i][1], f[i - 1][0]);
                f[i][0] = min(f[i][0], f[i - 1][0]);
            }
        }
        cout << min(f[n][0], f[n][1]) << endl;
    }

    return 0;
}
