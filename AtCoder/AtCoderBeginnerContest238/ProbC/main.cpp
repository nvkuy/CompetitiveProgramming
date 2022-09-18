#include <bits/stdc++.h>

using namespace std;

long long mod = 998244353, inv2 = 499122177;

long long cal(long long l, long long r) {
    long long n = r - l + 1LL;
    return ((((n % mod) * ((n + 1LL) % mod)) % mod) * inv2) % mod;
}

int main()
{

    long long l = 1LL, n, ans = 0LL;
    cin >> n;
    while (l <= n) {
        ans = (ans + cal(l, min(n, l * 10LL - 1LL))) % mod;
        l *= 10LL;
    }
    cout << ans;

    return 0;
}
