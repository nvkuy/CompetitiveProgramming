#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n, s, ans;
    double avr;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n);
        ans = 0, s = 0;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a.begin(), a.end());
        for (int i = 1; i < n; i++) {
            avr = (double)((double)a[0] + (double)a[i]) / 2.0;
            if (avr < a[i])
                ans++;
        }
        cout << ans << endl;
    }

    return 0;
}
