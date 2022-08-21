#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

long long f[1001], mod = 1e6 + 3;

long long modExpo(long long x, long long n, long long M){
    if(n == 0)
        return 1;
    else if(n % 2 == 0)
        return modExpo((x * x) % M, n / 2, M);
    else
        return (x * modExpo((x * x) % M, (n - 1) / 2, M)) % M;
}

long long dp(int n) {
    if (n < 1)
        return 0LL;
    if (f[n] == 0)
        f[n] = (dp(n - 1) + ((2LL * dp(n - 2)) % mod) + modExpo(2, n - 1, mod)) % mod;
    return f[n];
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    cout << dp(n);

    return 0;
}
