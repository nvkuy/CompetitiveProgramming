#include <bits/stdc++.h>
using namespace std;

int main() {

    long long m, k, mod = 1e9 + 7;
    cin >> m >> k;
    vector<long long> pf(k, 0), f = pf;
    pf[0] = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) {
            (f[(j + 1) % k] += (pf[j] * 3LL)) %= mod;
            (f[(j + 2) % k] += (pf[j] * 3LL)) %= mod;
            (f[j] += pf[j]) %= mod;
        }
        pf = f;
        fill(f.begin(), f.end(), 0);
    }
    pf[0]--;
    if (pf[0] < 0) pf[0] += mod;
    cout << pf[0] << endl;

    return 0;
}