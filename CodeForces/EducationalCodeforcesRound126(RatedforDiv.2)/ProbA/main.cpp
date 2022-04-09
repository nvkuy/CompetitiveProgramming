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
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        long long ans = 0, tmp;
        for (int i = 1; i < n; i++) {
            if (abs(a[i] - a[i - 1]) + abs(b[i] - b[i - 1]) > abs(a[i] - b[i - 1]) + abs(b[i] - a[i - 1]))
                swap(a[i], b[i]);
            ans += (abs(a[i] - a[i - 1]) + abs(b[i] - b[i - 1]));
        }
        cout << ans << endl;
    }

    return 0;
}
