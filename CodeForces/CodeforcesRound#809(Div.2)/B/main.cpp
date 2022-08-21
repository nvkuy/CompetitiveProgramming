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
        vector<pair<int, int>> ans(n + 1, {0, 0});
        for (int i = 0; i < n; i++) {
            if (i % 2)
                ans[a[i]].first = ans[a[i]].second + 1;
            else
                ans[a[i]].second = ans[a[i]].first + 1;
        }
        for (int i = 1; i <= n; i++)
            cout << max(ans[i].first, ans[i].second) << ' ';
        cout << endl;
    }

    return 0;
}
