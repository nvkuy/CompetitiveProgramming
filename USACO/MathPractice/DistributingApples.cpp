#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e6;
const long long mod = 1e9 + 7;
long long fac[MAXN + 1], inv_fac[MAXN + 1];

long long power(long long num, long long pow) {
    if (pow == 0) return 1;
    if (num >= mod) return power(num % mod, pow);
    if (pow % 2) return (num * power(num, pow - 1)) % mod;
    return power(num * num, pow / 2);
}

int main() {

    fac[0] = 1, inv_fac[0] = power(fac[0], mod - 2);
    for (long long i = 1; i <= MAXN; i++) {
        fac[i] = (fac[i - 1] * i) % mod;
        inv_fac[i] = power(fac[i], mod - 2);
    }

    long long n, m;
    cin >> n >> m;
    long long ans = fac[n + m - 1];
    ans *= inv_fac[n - 1];
    ans %= mod;
    ans *= inv_fac[m];
    ans %= mod;
    cout << ans << endl;

    return 0;
}