#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, a, b;
    cin >> n;
    vector<pair<int, int>> movs;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        movs.push_back(make_pair(b, a));
    }
    sort(movs.begin(), movs.end());

    int ti = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        if (movs[i].second >= ti) {
            ti = movs[i].first;
            ans++;
        }
    }
    cout << ans;

    return 0;
}
