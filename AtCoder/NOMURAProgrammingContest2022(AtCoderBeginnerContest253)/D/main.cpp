#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return a * (b / gcd(a, b));
}

long long cal(long long n, long long x) {
    long long ans = x, tmp = n / x;
    tmp = (tmp * (tmp + 1LL)) / 2LL;
    ans *= tmp;
    return ans;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long n, a, b, ans = 0;
    cin >> n >> a >> b;
    ans = cal(n, 1) + cal(n, lcm(a, b));
    ans -= (cal(n, a) + cal(n, b));
    cout << ans;

    return 0;
}
