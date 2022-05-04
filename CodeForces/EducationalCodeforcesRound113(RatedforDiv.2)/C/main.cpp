#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

long long maxN = 2e5, mod = 998244353;
vector<long long> f(maxN + 1);

long long modExpo(long long x, long long n, long long M){
    if(n == 0)
        return 1;
    else if(n % 2 == 0)
        return modExpo((x * x) % M, n / 2, M);
    else
        return (x * modExpo((x * x) % M, (n - 1) / 2, M)) % M;
}

long long modInvFE(long long A, long long M) {
    return modExpo(A, M - 2, M);
}

long long Permutation(long long n, long long k) {
    long long inv = modInvFE(f[n - k], mod);
    return (f[n] * inv) % mod;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    f[0] = f[1] = 1;
    for (long long i = 2; i <= maxN; i++)
        f[i] = (f[i - 1] * i) % mod;
    //cout << Permutation(5, 3) << endl;

    long long t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a.begin(), a.end(), greater<long long>());
        if (a[0] == a[1]) {
            cout << f[n] << endl;
            continue;
        }
        if (a[0] - a[1] > 1) {
            cout << "0" << endl;
            continue;
        }
        long long secondLargestElement = 0;
        for (int i = 1; i < n; i++) {
            if (a[i] == a[1])
                secondLargestElement++;
            else
                break;
        }
        long long ans = 0;
        for (long long numberOfRightElement = 0; numberOfRightElement < n; numberOfRightElement++) {
            //cout << ans << endl;
            if (numberOfRightElement < secondLargestElement) {
                ans = (ans + f[n - 1]) % mod;
                continue;
            }
            ans = (ans + ((f[n - 1] + mod - ((Permutation(numberOfRightElement, secondLargestElement) * f[n - secondLargestElement - 1]) % mod)) % mod)) % mod;
        }
        cout << ans << endl;
    }

    return 0;
}
