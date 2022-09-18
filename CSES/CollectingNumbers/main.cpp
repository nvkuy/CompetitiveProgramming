#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, ai, ans = 1;
    cin >> n;
    vector<pair<int, int>> a;
    for (int i = 0; i < n; i++) {
        cin >> ai;
        a.push_back(make_pair(ai, i));
    }
    sort(a.begin(), a.end());
    for (int i = 1; i < n; i++) {
        if (a[i].second < a[i - 1].second)
            ans++;
    }
    cout << ans;

    return 0;
}
