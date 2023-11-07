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

const long long mod = 1e9 + 7;
const int MAXN = 2e5;

long long fac[MAXN + 1], iv_fac[MAXN + 1];

long long power(long long num, long long pow) {
    if (pow == 0) return 1;
    if (num >= mod) num %= mod;
    if (pow % 2) return (num * power(num, pow - 1)) % mod;
    return power(num * num, pow / 2);
}

long long ckn(long long k, long long n) {
    if (k > n) return 0;
    return (((fac[n] * iv_fac[k]) % mod) * iv_fac[n - k]) % mod;
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
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> psCnt(n + 1, 0);
        for (int i = 0; i < n; i++) {
            int ai;
            cin >> ai;
            psCnt[ai]++;
        }
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            psCnt[i] += psCnt[i - 1];
            int j = max(1, i - k);
            ans += ckn(m, psCnt[i] - psCnt[j - 1]) + mod - ckn(m, psCnt[i - 1] - psCnt[j - 1]);
        }
        ans %= mod;
        cout << ans << endl;
    }

    return 0;
}
