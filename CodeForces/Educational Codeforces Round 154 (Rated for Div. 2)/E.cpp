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

const long long mod = 998244353, MAXN = 4004;
long long per[MAXN + 1];

int main()
{


    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    per[0] = 1;
    for (int i = 1; i <= MAXN; i++)
        per[i] = (per[i - 1] * i) % mod;

    long long n, k;
    cin >> n >> k;
    vector<vector<int>> f(n + 1, vector<int>(k + 1, 0));
    f[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++)
            f[i][j] = f[i - 1][j];
        int pre = i - k;
        if (pre < 0) continue;
        for (int j = 1; j <= k; j++) {
            f[i][j] += (per[k] * f[pre][j - 1]);
            f[i][j] %= mod;
        }
    }
    long long ans = 0;
    for (long long cost = 0; cost <= k; cost++) {
        ans += f[n][cost] * cost;
        ans %= mod;
    }
    cout << ans << endl;

    return 0;
}
