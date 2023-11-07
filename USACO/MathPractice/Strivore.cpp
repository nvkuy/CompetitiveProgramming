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
const int MAXN = 2e6 + 10;

long long fac[MAXN + 1], iv_fac[MAXN + 1], p25[MAXN + 1], p26[MAXN + 1];

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

/*

    consider a random string SS of length len(s) + k
    => for SS to be the string generate from s with k operation then SS have to contain s as substring
    => choose n position in SS to place s characters

    for pos s_i in SS is choosen to place char i of s => from [s_(i - 1) + 1, s_i - 1] can't place any char s_i
    => true for all s_i (i > 1) and with i = 1 then true for range [0, s_1 - 1]
    => all pos <= s_n and pos != s_i then there are 25 character to choose, pos > s_n there are 26 ways
    => try all s_n => ans

*/

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    fac[0] = iv_fac[0] = 1;
    p25[0] = p26[0] = 1;
    for (long long i = 1; i <= MAXN; i++) {
        fac[i] = (fac[i - 1] * i) % mod;
        iv_fac[i] = power(fac[i], mod - 2);
        p25[i] = (p25[i - 1] * 25LL) % mod;
        p26[i] = (p26[i - 1] * 26LL) % mod;
    }

    int k;
    string s;
    cin >> k >> s;
    
    int len = k + s.length(), n = s.length();
    long long ans = 0;
    for (int i = 0; i < len; i++) {
        int pre = i, suf = len - i - 1, rm_pre = max(pre - (n - 1), 0);
        long long suf_ways = p26[suf];
        long long choose_s = ckn(n - 1, pre);
        long long choose_rm = p25[rm_pre];
        long long pre_ways = (choose_s * choose_rm) % mod;
        ans += pre_ways * suf_ways;
        ans %= mod;
    }
    
    cout << ans << endl;

    return 0;
}
