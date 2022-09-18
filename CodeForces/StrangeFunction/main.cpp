#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return (a / gcd(a, b)) * b;
}

int main()
{
    int t;
    long long n, curLcm, preLcm, ans, mod = 1e9 + 7;
    cin >> t;
    while (t--) {
        cin >> n;
        preLcm = 1, ans = 0;
        for (long long i = 2; i < 101; i++) {
            if (preLcm > n)
                break;
            curLcm = lcm(preLcm, i);
            ans = (ans + (i * (((n / preLcm) - (n / curLcm)) % mod) % mod)) % mod;
            preLcm = curLcm;
        }
        cout << ans << endl;
    }


    return 0;
}
