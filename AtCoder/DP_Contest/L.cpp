#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

long long f[3003][3003];
long long a[3003];
const long long MINUS_INF = -1e18;

long long cnt = 0;

long long cal(int l, int r) {
    // cout << ++cnt << endl;
    if (l == r)
        return a[l];
    if (l + 1 == r)
        return max(a[l], a[r]) - min(a[l], a[r]);
    if (f[l][r] != MINUS_INF)
        return f[l][r];
    long long ans1 = min(a[l] - a[l + 1] + cal(l + 2, r), a[l] - a[r] + cal(l + 1, r - 1));
    long long ans2 = min(a[r] - a[r - 1] + cal(l, r - 2), a[r] - a[l] + cal(l + 1, r - 1));
    f[l][r] = max(ans1, ans2);
    return f[l][r];
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            f[i][j] = MINUS_INF;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << cal(0, n - 1) << endl;

    return 0;
}