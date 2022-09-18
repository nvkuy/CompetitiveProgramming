#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, s, t;
    cin >> t;
    while (t--) {
        cin >> n >> s;
        vector<int> a(n), ps(n + 1, 0);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++)
            ps[i] = ps[i - 1] + a[i - 1];
        int ans = n + 1;
        for (int i = 1; i <= n; i++) {
            if (ps[n] - ps[i - 1] < s)
                break;
            int l = i, r = n, m;
            while (l < r) {
                if (r - l == 1) {
                    if (ps[r] - ps[i - 1] == s)
                        l = r;
                    break;
                }
                m = (l + r) / 2;
                if (ps[m] - ps[i - 1] <= s)
                    l = m;
                else
                    r = m - 1;
            }
            ans = min(ans, n - (l - i + 1));
        }
        if (ans > n)
            ans = -1;
        cout << ans << endl;
    }

    return 0;
}
