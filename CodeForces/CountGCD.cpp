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

const int MAXN = 1e5;
const long long mod = 998244353;
int notPrime[MAXN + 1];
vector<int> primes;

long long phi(long long n, long long m) { // count number k that gcd(n, k) == 1 and k <= m
    vector<int> fac;
    for (int p : primes) {
        if (p * p > n) break;
        if (n % p == 0) {
            fac.push_back(p);
            while (n % p == 0) n /= p;
        }
    }
    if (n > 1) fac.push_back(n);
    int prime_cnt = fac.size();
    long long cnt = 0;
    for (int i = 1; i < (1 << prime_cnt); i++) {
        long long lcm_mask = 1;
        for (int j = 0; j < prime_cnt; j++) {
            if ((i >> j) & 1)
                lcm_mask = min(m + 1, lcm_mask * fac[j]);
        }
        cnt += (m / lcm_mask) * (bit_cnt(i) % 2 ? 1 : -1);
    }
    return m - cnt;
}

// count x <= m: gcd(a[i - 1], x) = a[i] 
// => (a[i - 1] % a[i] == 0 && x % a[i] == 0) 
// => count x <= m: gcd(a[i - 1] / a[i], x / a[i]) = 1
long long cal(long long pre_a, long long cur_a, long long m) {
    if (pre_a % cur_a > 0) return 0;
    return phi(pre_a / cur_a, m / cur_a);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    memset(notPrime, 0, sizeof(notPrime));
    notPrime[0] = notPrime[1] = 1;
    for (int i = 2; i * i <= MAXN; i++) {
        if (!notPrime[i])
            for (int j = i * i; j <= MAXN; j += i) notPrime[j] = 1;
    }
    for (int i = 0; i <= MAXN; i++)
        if (!notPrime[i]) primes.push_back(i);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        long long ans = 1;
        for (int i = 1; i < n; i++) {
            if (a[i] == a[i - 1]) {
                long long tmp = m / a[i];
                ans = (ans * tmp) % mod;
                continue;
            }
            ans = (ans * cal(a[i - 1], a[i], m)) % mod;
            if (ans == 0) break;
        }
        cout << ans << endl;
    }

    return 0;
}
