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
        long long n, k, x;
        cin >> n >> k >> x;
        vector<long long> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            a[i] -= x;
        }
        vector<vector<long long>> f(n + 1, vector<long long>(k + 2, -1e18));
        f[0][k] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = max(k - i, 0LL); j <= k; j++) {
                f[i][j] = 0;
                f[i][j] = max(f[i][j], f[i - 1][j] + a[i]);
                f[i][j] = max(f[i][j], f[i - 1][j + 1] + a[i] + 2LL * x);
            }
        }
        long long ans = -1e18;
        for (int i = 0; i <= n; i++) {
            long long rm = max(min(k, n - i), 0LL);
            for (int j = 0; j <= rm; j++)
                ans = max(ans, f[i][j]);
        }
        cout << ans << endl;
    }

    return 0;
}
