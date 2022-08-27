#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n), dp(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++) {
            dp[i] = 1;
            for (int j = max(0, i - 404); j < i; j++) {
                if ((a[j] ^ i) < (a[i] ^ j))
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        int ans = 1;
        for (int i = 0; i < n; i++)
            ans = max(ans, dp[i]);
        cout << ans << endl;
    }

    return 0;
}
