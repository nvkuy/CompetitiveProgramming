#include <bits/stdc++.h>

using namespace std;

long long mod = 998244353;
map<long long, long long> f;

long long cal(long long x) {
    if (x <= 4)
        return x;
    else {
        if (f[x / 2] == 0)
            f[x / 2] = cal(x / 2);
        if (f[(x / 2) + (x % 2)] == 0)
            f[(x / 2) + (x % 2)] = cal((x / 2) + (x % 2));
        return (f[x / 2] * f[(x / 2) + (x % 2)]) % mod;
    }
}

int main()
{

    long long x;
    cin >> x;
    cout << cal(x);

    return 0;
}
