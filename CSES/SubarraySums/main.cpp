#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long n, x;
    map<long long, int> cnt;
    cnt[0]++;

    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    long long cs = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        cs += a[i];
        ans += cnt[cs - x];
        cnt[cs]++;
    }
    cout << ans;

    return 0;
}
