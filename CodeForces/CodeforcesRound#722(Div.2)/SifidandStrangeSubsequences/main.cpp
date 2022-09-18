#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n, ans;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n);
        ans = 1;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a.begin(), a.end());
        while (a.size() > 1 && a[a.size() - 2] > 0)
            a.pop_back();
        ans = max(ans, (int)(a.size() - 1));
        int prev = a[0], tans = 1;
        for (int i = 1; i < a.size(); i++) {
            if (a[i] - prev >= a.back()) {
                tans++;
                prev = a[i];
            }
        }
        ans = max(ans, tans);
        cout << ans << endl;
    }

    return 0;
}
