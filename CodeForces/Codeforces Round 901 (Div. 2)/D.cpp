#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'
#define bit_cnt(x) __builtin_popcountll(x)
#define low_bit(x) __builtin_ctzll(x)

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
        vector<long long> cnt(n + 2, 0);
        for (int i = 0; i < n; i++) {
            int ai;
            cin >> ai;
            if (ai <= n) cnt[ai]++;
        }
        int mex = 0;
        while (cnt[mex] > 0) mex++;
        vector<vector<long long>> f(n + 2, vector<long long>(n + 2, 1e18));
        f[mex][mex] = 0;
        for (long long i = mex - 1; i >= 0; i--) {
            for (long long j = 0; j <= mex; j++) {
                f[i][j] = min(f[i][j], f[i + 1][j]);
                f[i][i] = min(f[i][i], (cnt[i] - 1LL) * j + i + f[i + 1][j]);
            }
        }
        cout << f[0][0] << endl;
    }

    return 0;
}
