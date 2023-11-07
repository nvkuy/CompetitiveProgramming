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

const long long mod = 998244353;
const int MAXN = 505;

long long x, n;
long long f[MAXN + 1][MAXN + 1], xpy[MAXN + 1][MAXN + 1];
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

long long cal(int damage_taken, int remain_hero) {
    assert(remain_hero > 0 && damage_taken <= x);
    if (remain_hero == 1) return x - damage_taken;
    int dmg = remain_hero - 1, next_dmg = damage_taken + dmg;
    if (next_dmg >= x) return 0;
    if (f[damage_taken][remain_hero] == -1) {
        f[damage_taken][remain_hero] = 0;
        for (int next_rm = 1; next_rm <= remain_hero; next_rm++) {
            int new_dead = remain_hero - next_rm;
            f[damage_taken][remain_hero] += ((cal(next_dmg, next_rm) * xpy[dmg][new_dead]) % mod) * ckn(new_dead, remain_hero);
            f[damage_taken][remain_hero] %= mod;
        }
    }
    return f[damage_taken][remain_hero];
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

    for (int i = 0; i <= MAXN; i++) {
        xpy[i][0] = 1;
        f[i][0] = -1;
    }
    for (long long i = 0; i <= MAXN; i++) {
        for (int j = 1; j <= MAXN; j++) {
            f[i][j] = -1;
            xpy[i][j] = (xpy[i][j - 1] * i) % mod;
        }
    }

    cin >> n >> x;
    
    cout << (xpy[x][n] + mod - cal(0, n)) % mod << endl;

    return 0;
}
