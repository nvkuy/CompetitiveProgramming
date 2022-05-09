#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n), cnt(101, 0);
        bool hasZero = false;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            cnt[a[i]]++;
        }
        for (int i = 1; i <= 100; i++)
            if (cnt[i] > 1)
                hasZero = true;
        int ans = n;
        if (cnt[0] > 0) {
            hasZero = true;
            ans -= cnt[0];
        }
        if (!hasZero)
            ans++;
        cout << ans << endl;
    }

    return 0;
}
