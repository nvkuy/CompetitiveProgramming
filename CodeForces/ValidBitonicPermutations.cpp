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

const int MAXN = 100;
const long long mod = 1e9 + 7;
long long fac[MAXN + 1], iv_fac[MAXN + 1];

long long power(long long num, long long pow) {
    if (pow == 0) return 1;
    if (num >= mod) num %= mod;
    if (pow % 2) return (num * power(num, pow - 1)) % mod;
    return power(num * num, pow / 2);
}

long long ckn(long long k, long long n) {
    if (k > n) return 0;
    return (((fac[n] * iv_fac[n - k]) % mod) * iv_fac[k]) % mod;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    fac[0] = iv_fac[0] = 1;
    for (long long i = 1; i <= MAXN; i++) {
        fac[i] = (fac[i - 1] * i) % mod;
        iv_fac[i] = power(fac[i], mod - 2);
    }

    int t;
    cin >> t;
    while (t--) {
        int n, i, j, x, y;
        cin >> n >> i >> j >> x >> y;
        if (x == n) {
            int g1 = j - i - 1, g2 = n - j, d1 = x - y - 1, d2 = y - 1;
            cout << (ckn(g1, d1) * ckn(g2, d2)) % mod << endl;
            continue;
        }
        if (y == n) {
            int g1 = i - 1, g2 = j - i - 1, d1 = x - 1, d2 = y - x - 1;
            cout << (ckn(g1, d1) * ckn(g2, d2)) % mod << endl;
            continue;
        }
        long long ans = 0;
        for (int k = 1; k <= n; k++) {
            if (k == i || k == j) continue;
            long long tans = 1;
            if (k < i) {
                int g1 = i - k - 1, g2 = j - i - 1, g3 = n - j;
                int d1 = n - x - 1, d2 = x - y - 1, d3 = y - 1;
                tans = (tans * ckn(g1, d1)) % mod;
                tans = (tans * ckn(g2, d2)) % mod;
                tans = (tans * ckn(g3, d3)) % mod;
            } else if (k > j) {
                int g1 = i - 1, g2 = j - i - 1, g3 = k - j - 1;
                int d1 = x - 1, d2 = y - x - 1, d3 = n - y - 1;
                tans = (tans * ckn(g1, d1)) % mod;
                tans = (tans * ckn(g2, d2)) % mod;
                tans = (tans * ckn(g3, d3)) % mod;
            } else {
                //..
            }
            ans += tans;
            ans %= mod;
        }
        cout << ans << endl;
    }

    return 0;
}
