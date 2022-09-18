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
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        vector<int> f;
        f.push_back(a[0]);
        for (int i = 1; i < n; i++)
            f.push_back(f.back() + a[i]);
        int s = 0, ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            s += a[i];
            int j = lower_bound(f.begin(), f.begin() + i, s) - f.begin();
            if (j < i && f[j] == s)
                ans = max(ans, n - (i - j - 1));
        }
        cout << ans << endl;
    }

    return 0;
}
