#include <bits/stdc++.h>

using namespace std;

const int mn = 2e5 + 2;
long long mod = 1e9 + 7, p2[mn];

int main()
{
    long long t, n, m, l, r, x, ax;
    p2[0] = 1LL;
    for (long long i = 1; i < mn; i++)
        p2[i] = (p2[i - 1] * 2LL) % mod;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        ax = 0LL;
        while (m--) {
            cin >> l >> r >> x;
            ax |= x;
        }
        cout << (ax * p2[n - 1]) % mod << endl;
    }

    return 0;
}
