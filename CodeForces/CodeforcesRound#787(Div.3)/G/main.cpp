#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    reverse(a.begin(), a.end());
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        m -= a[i];
        int diff;
        for (int j = a[i]; j >= -m; j--) {
            diff = a[i] - j;
            if (j <= ((diff + m) / (n - i - 1)) && j <= (a[i + 1] + diff))
                break;
        }
        a[i] -= diff;
        a[i + 1] += diff;
        ans += diff;
    }
    cout << ans;

    return 0;
}
