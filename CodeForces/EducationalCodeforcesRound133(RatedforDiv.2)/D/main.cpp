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

    int n, k, mod = 998244353;
    cin >> n >> k;
    vector<int> ans(n + 1, 0);
    vector<int> f1(n + 1, 0), f2(n + 1, 0);
    f1[0] = 1;
    for (int step = 1; step * step <= 2 * n; step++) {
        for (int i = 1; i <= n; i++) {
            int j = i - k - step + 1;
            if (j < 0)
                continue;
            f2[i] = (f2[i] + f1[j]) % mod;
            f2[i] = (f2[i] + f2[j]) % mod;
        }
        for (int i = 1; i <= n; i++)
            ans[i] = (ans[i] + f2[i]) % mod;
        f1 = f2;
        fill(f2.begin(), f2.end(), 0);
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';

    return 0;
}
