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

    long long n, q, mod = 1e9 + 7;
    cin >> n >> q;
    vector<long long> a(n + 1), ps1(n + 1, 0), ps2(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++) {
        ps1[i] = (ps1[i - 1] + a[i]) % mod;
        ps2[i] = (ps2[i - 1] + ps1[i - 1] * a[i]) % mod;
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        long long ans = (ps2[r] + mod - ps2[l - 1]) % mod;
        long long tmp = (ps1[r] + mod - ps1[l - 1]) % mod;
        ans = (ans + mod * mod - tmp * ps1[l - 1]) % mod;
        cout << ans << endl;
    }

    return 0;
}
