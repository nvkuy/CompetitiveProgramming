#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    long long ans = 0;
    int j = 0, curDV = 0;
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        if (cnt[a[i]] == 0)
            curDV++;
        cnt[a[i]]++;
        while (curDV > k) {
            cnt[a[j]]--;
            if (cnt[a[j]] == 0)
                curDV--;
            j++;
        }
        ans += (i - j + 1);
    }
    cout << ans;

    return 0;
}
