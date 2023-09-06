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

const long long mod = 998244353, MAXN = 2022, MAXA = 1e6;
long long per[2 * MAXN + 2], inv_per[2 * MAXN + 2], f[MAXN + 1], pf[MAXN + 1];
int sieve[MAXA + 1];

long long power(long long num, long long pow) {
    if (pow == 0) return 1;
    if (pow & 1) return (num * power(num, pow - 1)) % mod;
    return power((num * num) % mod, pow >> 1);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    per[0] = 1;
    for (int i = 1; i <= 2 * MAXN; i++) per[i] = (per[i - 1] * i) % mod;
    for (int i = 0; i <= 2 * MAXN; i++) inv_per[i] = power(per[i], mod - 2);
    for (int i = 2; i <= MAXA; i++) sieve[i] = 1;
    for (int i = 2; i * i <= MAXA; i++) {
        if (sieve[i]) {
            for (int j = i * i; j <= MAXA; j += i)
                sieve[j] = 0;
        }
    }

    int n;
    cin >> n;
    map<int, int> cnt;
    for (int i = 0; i < 2 * n; i++) {
        int ai;
        cin >> ai;
        cnt[ai]++;
    }

    vector<pair<int, int>> a(cnt.begin(), cnt.end());
    // vector<long long> pf(n + 1, 0), f = pf;
    memset(pf, 0, sizeof(pf));
    pf[0] = 1;
    for (auto p : a) {
        // fill(f.begin(), f.end(), 0);
        memset(f, 0, sizeof(f));
        for (int i = 0; i <= n; i++) {
            if (sieve[p.first] && i + p.second - 1 <= n && pf[i] > 0) {
                f[i + p.second - 1] += pf[i] * ((((per[i + p.second - 1] * inv_per[i]) % mod) * inv_per[p.second - 1]) % mod);
                f[i + p.second - 1] %= mod;
            }
            if (i + p.second <= n && pf[i] > 0) {
                f[i + p.second] += pf[i] * ((((per[i + p.second] * inv_per[i]) % mod) * inv_per[p.second]) % mod);
                f[i + p.second] %= mod;
            }
        }
        // pf = f;
        for (int i = 0; i <= n; i++) pf[i] = f[i];
    }

    cout << f[n] << endl;

    return 0;
}
