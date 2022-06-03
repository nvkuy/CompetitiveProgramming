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

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        long long a1, d1, a2, c1, d3, c2, ans = 0, mod = 1e9 + 7;
        cin >> a1 >> d1 >> a2 >> c1 >> d3 >> c2;
        long long last_a = a1 + (a2 - 1LL) * d1, last_c = c1 + (c2 - 1LL) * d3;
        if (d3 % d1 != 0 || (c1 - a1) % d1 != 0 || last_a < last_c || c1 < a1) {
            cout << "0" << endl;
            continue;
        }
        long long pre_first_c = c1 - d3, next_last_c = last_c + d3;
        if (pre_first_c < a1 || next_last_c > last_a) {
            cout << "-1" << endl;
            continue;
        }
        for (long long i = 1; i * i <= d3; i++) {
            if (d3 % i != 0)
                continue;
            long long d21 = i, d22 = d3 / i;
            if (lcm(d21, d1) == d3)
                ans = (ans + (((d3 / d21) * (d3 / d21)) % mod)) % mod;
            if (d22 != d21 && lcm(d22, d1) == d3)
                ans = (ans + (((d3 / d22) * (d3 / d22)) % mod)) % mod;
        }
        cout << ans << endl;
    }

    return 0;
}
