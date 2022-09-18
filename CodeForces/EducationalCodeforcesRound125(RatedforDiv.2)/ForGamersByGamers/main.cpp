#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long n, c, ci, hi, di, m;
    cin >> n >> c;
    vector<long long> maxPowByCost(c + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> ci >> di >> hi;
        maxPowByCost[ci] = max(maxPowByCost[ci], di * hi);
    }
    for (long long i = 1; i <= c; i++)
        for (long long j = i; j <= c; j += i)
            maxPowByCost[j] = max(maxPowByCost[j], (j / i) * maxPowByCost[i]);
    ci = 0;
    for (int i = 1; i <= c; i++) {
        ci = max(ci, maxPowByCost[i]);
        maxPowByCost[i] = ci;
    }
    cin >> m;
    while (m--) {
        cin >> di >> hi;
        ci = upper_bound(maxPowByCost.begin(), maxPowByCost.end(), di * hi) - maxPowByCost.begin();
        if (ci > c)
            ci = -1;
        cout << ci << ' ';
    }

    return 0;
}
