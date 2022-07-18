#include <bits/stdc++.h>

using namespace std;

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

long long modInvFE(long long A,long long M) {
    return modExpo(A,M-2,M);
}

long long modMul(long long a, long long b, long long mod) {
    return ((a % mod) * (b % mod)) % mod;
}

long long modAdd(long long a, long long b, long long mod) {
    return (a + b) % mod;
}

long long modDiv(long long a, long long b, long long mod) {
    return modMul(a, modInvFE(b, mod), mod);
}

long long mod = 1e9 + 7;
long long n, m;

long long comb(long long a, long long b) {
    long long t1 = 1, t2 = 1, t3 = 1;
    for (long long i = 1; i <= a; i++)
        t1 = modMul(t1, i, mod);
    for (long long i = 1; i <= b; i++)
        t2 = modMul(t2, i, mod);
    for (long long i = 1; i <= a - b; i++)
        t3 = modMul(t3, i, mod);
    return modDiv(t1, modMul(t2, t3, mod), mod);
}

long long calWithAvr(int avr) {
    vector<vector<long long>> f(n + 1, vector<long long>(m * n + 1, 0));
    f[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (j == avr)
                continue;
            for (int k = 0; k + j <= n * m; k++)
                f[i][k + j] = (f[i][k + j] + f[i - 1][k]) % mod;
        }
    }
    long long ans = 0;
    for (int i = 0; i <= n; i++) {
        long long ts = i * avr;
        ans = (ans + ((((f[i][ts] * (n - i)) % mod) * comb(n, i)) % mod)) % mod;
        //cout << avr << '|' << f[i][ts] << endl;
    }
    return ans;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long ans;
    cin >> n >> m;
    while (n != 0 || m != 0) {
        ans = 0;
        for (int i = 0; i <= m; i++)
            ans = (ans + calWithAvr(i));
        cout << ans << endl;
        cin >> n >> m;
    }

    return 0;
}
