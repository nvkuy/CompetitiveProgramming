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

/*

    error is the number of bad position of "0"
    let f[error] is expected number of swap to sort => f[0] = 0, f[error] is answer
    let p the probability swap to make error -> error - 1 => p = (error * error) / (n * (n - 1) / 2)

    we have f[er] = 1 + f[er - 1] * p + (1 - p) * f[er]
    <=> p * f[er] = 1 + f[er - 1] * p
    <=> f[er] = 1 / p + f[er - 1]

*/

const long long mod = 998244353;

long long pow_mod(long long a, long long b) {
    if (b == 0) return 1;
    a %= mod;
    if (b % 2) return (a * pow_mod(a, b - 1)) % mod;
    return pow_mod(a * a, b / 2);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        int zero = n - accumulate(a.begin(), a.end(), 0);
        int bad = accumulate(a.begin(), a.begin() + zero, 0);
        long long choose_ij = (n * (n - 1) / 2) % mod;
        vector<long long> f(bad + 1, 0);
        f[0] = 0;
        for (long long i = 1; i <= bad; i++) {
            f[i] += f[i - 1];
            f[i] += (choose_ij * pow_mod(i * i, mod - 2)) % mod;
            f[i] %= mod;
        }
        cout << f[bad] << endl;
    }

    return 0;
}
