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

// idea: dp on contribution of each bit
const long long mod = 998244353;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    long long ans = 0;
    for (int bit = 0; bit <= 30; bit++) {
        vector<pair<long long, long long>> f0(n, {0, 0}), f1(n, {0, 0});
        if ((a[0] >> bit) & 1)
            f1[0] = {1, 1};
        else
            f0[0] = {1, 1};
        for (int i = 1; i < n; i++) {
            if ((a[i] >> bit) & 1) {
                f1[i] = {1, 1};
                f1[i].first += f0[i - 1].first + f0[i - 1].second;
                f1[i].second += f0[i - 1].second;
                f0[i].first += f1[i - 1].first + f1[i - 1].second;
                f0[i].second += f1[i - 1].second;
            } else {
                f0[i] = {1, 1};
                f1[i].first += f1[i - 1].first + f1[i - 1].second;
                f1[i].second += f1[i - 1].second;
                f0[i].first += f0[i - 1].first + f0[i - 1].second;
                f0[i].second += f0[i - 1].second;
            }
            f0[i].first %= mod;
            f0[i].second %= mod;
            f1[i].first %= mod;
            f1[i].second %= mod;
        }
        long long val = (1LL << bit) % mod;
        for (int i = 0; i < n; i++) {
            ans += (f1[i].first * val) % mod;
            ans %= mod;
        }
    }
    cout << ans << endl;

    return 0;
}
