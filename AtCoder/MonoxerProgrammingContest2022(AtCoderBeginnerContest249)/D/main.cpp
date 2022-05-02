#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long n, maxAi = 2e5, ans = 0, ai;
    cin >> n;
    vector<long long> cnt(maxAi + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> ai;
        cnt[ai]++;
    }
    for (long long i = 1; i <= maxAi; i++) {
        if (cnt[i] <= 0)
            continue;
        for (long long j = 1; i * j <= maxAi; j++)
            ans += (cnt[i] * cnt[j] * cnt[i * j]);
    }
    cout << ans;

    return 0;
}
