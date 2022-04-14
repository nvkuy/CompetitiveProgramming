#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, k, x;
    cin >> n >> k >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++) {
        if (k <= 0)
            break;
        int tmp = min(a[i] / x, k);
        k -= tmp;
        a[i] -= (tmp * x);
    }
    sort(a.begin(), a.end(), greater<int>());
    for (int i = 0; i < n; i++) {
        if (k <= 0)
            break;
        a[i] = 0;
        k--;
    }
    long long ans = 0;
    for (int i = 0; i < n; i++)
        ans += a[i];
    cout << ans;

    return 0;
}
