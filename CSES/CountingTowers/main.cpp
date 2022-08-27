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

    long long t, n = 1e6, mod = 1e9 + 7;
    vector<vector<long long>> f(n + 1, vector<long long>(2));
    f[1][0] = f[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        f[i][0] = (f[i - 1][0] * 2 + f[i - 1][1]) % mod;
        f[i][1] = (f[i - 1][0] + 4 * f[i - 1][1]) % mod;
    }
    cin >> t;
    while (t--) {
        cin >> n;
        cout << (f[n][0] + f[n][1]) % mod << endl;
    }

    return 0;
}
