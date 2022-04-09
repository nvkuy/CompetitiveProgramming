#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, x;
    map<long long, int> cnt;
    cnt[0]++;

    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    long long cs = 0, ans = (x == 0);
    for (int i = 0; i < n; i++) {
        cs += a[i];
        ans += cnt[x - cs];
        if (a[i] - cs != 0)
            cnt[a[i] - cs]++;
    }
    cout << ans;

    return 0;
}
