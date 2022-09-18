#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7, mn = 2e5 + 2;
long long f[mn];

int main()
{

    f[0] = 1LL;
    for (int i = 1; i < mn; i++)
        f[i] = (f[i - 1] * i) % mod;
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        cout << (f[2 * n] * ((mod + 1) / 2)) % mod << endl;
    }

    return 0;
}
