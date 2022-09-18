#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long n, k, p, ans = 1e18, tmp;
    cin >> n >> k >> p;
    vector<long long> a(n), b(k);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < k; i++)
        cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i = 0; i + n <= k; i++) {
        tmp = 0;
        for (int j = i; j < i + n; j++)
            tmp = max(tmp, (llabs(a[j - i] - b[j]) + llabs(p - b[j])));
        ans = min(ans, tmp);
    }
    cout << ans;

    return 0;
}
