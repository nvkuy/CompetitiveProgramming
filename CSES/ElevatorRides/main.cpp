#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, x, full_mask;

    cin >> n >> x;
    vector<int> w(n);
    for (int i = 0; i < n; i++)
        cin >> w[i];

    full_mask = 1 << n;
    vector<pair<int, int>> f(full_mask, {21, x});
    f[0] = {1, 0};
    for (int mask = 0; mask < full_mask; mask++) {
        for (int i = 0; i < n; i++) {
            if (((1 << i) & mask) == 0)
                continue;
            int sub_mask = ((1 << i) ^ mask);
            if (f[sub_mask].second + w[i] <= x) {
                if (f[sub_mask].first > f[mask].first)
                    continue;
                if (f[sub_mask].first == f[mask].first && f[sub_mask].second + w[i] > f[mask].second)
                    continue;
                f[mask] = {f[sub_mask].first, f[sub_mask].second + w[i]};
            } else {
                if (f[sub_mask].first + 1 > f[mask].first)
                    continue;
                f[mask].first = f[sub_mask].first + 1;
                f[mask].second = min(f[mask].second, w[i]);
            }
        }
    }

    cout << f[full_mask - 1].first;

    return 0;
}
