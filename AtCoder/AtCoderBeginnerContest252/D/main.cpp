#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long n, ai, maxAi = 2e5;
    cin >> n;
    vector<long long> cnt(maxAi + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> ai;
        cnt[ai]++;
    }
    long long ans = (n * (n - 1LL) * (n - 2LL)) / 6LL;
    for (int i = 0; i <= maxAi; i++) {
        ans -= ((cnt[i] * (cnt[i] - 1LL) * (cnt[i] - 2LL)) / 6LL);
        ans -= (((cnt[i] * (cnt[i] - 1LL)) / 2LL) * (n - cnt[i]));
    }
    cout << ans;

    return 0;
}
