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

const int MAXN = 50000;
const long long mod = 1e9 + 7;
long long per[MAXN + 1];

long long power(long long n, long long pw) {
    if (pw == 0) return 1;
    if (pw % 2) return (n * power(n, pw - 1)) % mod;
    return power((n * n) % mod, pw / 2);
}

long long ckn(long long n, long long k) {
    return (per[n] * power((per[n - k] * per[k]) % mod, mod - 2)) % mod;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    per[0] = 1;
    for (int i = 1; i <= MAXN; i++)
        per[i] = (per[i - 1] * i) % mod;
    
    int n;
    cin >> n;

    long long cur = ckn(n, 0), ans = 0;
    for (int win = 1; win <= n; win++) {
        long long tmp = ckn(n, win);
        ans += (tmp * cur) % mod;
        cur += tmp;
        ans %= mod;
        cur %= mod;
    }

    cout << ans << endl;

    return 0;
}
