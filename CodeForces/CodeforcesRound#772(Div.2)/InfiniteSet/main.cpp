#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, p, ans = 0LL, ai, mod = 1e9 + 7, iv2 = (mod + 1) / 2;
    cin >> n >> p;
    for (int i = 0; i < n; i++) {
        cin >> ai;
        int tmp = 0;
        while (pow(2, tmp) < ai)
            tmp++;
        tmp = ((p - tmp) / 2) + 1;
        tmp = (((tmp * (tmp + 1)) % mod) * iv2) % mod;
        ans = (ans + tmp) % mod;
    }
    cout << ans;

    return 0;
}
