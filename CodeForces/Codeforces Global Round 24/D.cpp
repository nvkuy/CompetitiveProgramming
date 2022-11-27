#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

long long modExpo(long long x, long long n, long long M){
    if(n == 0)
        return 1;
    else if(n % 2 == 0)
        return modExpo((x * x) % M, n / 2, M);
    else
        return (x * modExpo((x * x) % M, (n - 1) / 2, M)) % M;
}

//isPrime(M) == true
long long modInvFE(long long A, long long M) {
    return modExpo(A, M - 2, M);
}

long long fact[5005], c[5005][5005], invFact[5005];

void init(long long mod, long long n) {
    fact[0] = 1, invFact[0] = modInvFE(1, mod);
    for (long long i = 1; i <= n; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
        invFact[i] = modInvFE(fact[i], mod);
    }
    for (int i = 0; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            c[i][j] = (((fact[j] * invFact[i]) % mod) * invFact[j - i]) % mod;
        }
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long n, mod;
    cin >> n >> mod;
    init(mod, n);
    long long ans = 0;
    for (long long i = n / 2; i <= n - 2; i++) {
        long long t2 = 0;
        for (long long j = 0; j < n / 2; j++) {
            if (i - j <= n / 2)
                t2++;
        }
        t2 = (t2 * n) % mod;
        for (long long j = 0; j <= n - i - 2; j++) {
            ans += (((c[j][n - i - 2] * t2) % mod) * fact[i + j - 1]);
            ans %= mod;
        }
    }
    if (n % 2 == 0)
        ans = (ans + (n * fact[n - 2])) % mod;
    cout << ans << endl;

    return 0;
}
