#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, pi;
    char c;
    cin >> n;
    vector<pair<int, bool>> a;
    for (int i = 0; i < n; i++) {
        cin >> c >> pi;
        bool tmp = 0;
        if (c == 'L')
            tmp = 1;
        a.push_back({pi, tmp});
    }
    sort(a.begin(), a.end());
    int ans = n;
    for (int i = 0; i < n; i++) {
        if (a[i].second)
            continue;
        int tans = 0;
        for (int j = 0; j < i; j++)
            if (a[j].second)
                tans++;
        for (int j = i; j < n; j++)
            if (!a[j].second && a[j].first > a[i].first)
                tans++;
        ans = min(ans, tans);
    }
    cout << ans;

    return 0;
}
