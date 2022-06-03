#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long n, m, mod = 998244353;
    cin >> n >> m;
    int highBit = 0;
    while ((1LL << highBit) < m)
        highBit++;
    if ((1LL << highBit) == m)
        highBit++;
    if (n > highBit) {
        cout << "0";
        return 0;
    }
    vector<long long> pf(highBit, 0), f(highBit, 0);
    vector<long long> useBitI(highBit, 0);
    for (int i = 0; i < highBit; i++)
        useBitI[i] = (min(1LL << (i + 1), m + 1) - (1LL << i)) % mod;
    for (int i = 0; i < highBit; i++)
        pf[i] = useBitI[i];
    for (int i = 1; i < n; i++) {
        fill(f.begin(), f.end(), 0);
        for (int j = 0; j < highBit; j++)
            for (int k = 0; k < j; k++)
                f[j] = (f[j] + pf[k] * useBitI[j]) % mod;
        pf = f;
    }
    long long ans = 0;
    for (int i = 0; i < highBit; i++)
        ans = (ans + pf[i]) % mod;
    cout << ans;

    return 0;
}
