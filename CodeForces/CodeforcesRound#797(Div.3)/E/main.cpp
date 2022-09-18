#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long t, n, k, ai;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        long long ans = 0;
        vector<int> modAi;
        for (int i = 0; i < n; i++) {
            cin >> ai;
            ans += (ai / k);
            modAi.push_back(ai % k);
        }
        sort(modAi.begin(), modAi.end());
        int l = 0, r = modAi.size() - 1;
        while (l < r) {
            if (modAi[r] + modAi[l] < k) {
                l++;
                continue;
            }
            ans++;
            r--, l++;
        }
        cout << ans << endl;
    }

    return 0;
}
