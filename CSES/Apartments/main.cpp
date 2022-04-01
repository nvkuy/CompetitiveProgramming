#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, k, ans = 0, sf;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    vector<bool> dd(m, false);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sf = 0;
    for (int i = 0; i < n; i++) {
        int j = lower_bound(b.begin() + sf, b.end(), a[i] - k) - b.begin();
        while (j < m && dd[j] && b[j] <= a[i] + k)
            j++;
        sf = j;
        if (j >= m || dd[j] || b[j] > a[i] + k)
            continue;
        ans++;
        dd[j] = true;
    }
    cout << ans;

    return 0;
}
