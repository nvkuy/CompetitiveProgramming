#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>> ans;
    ans.push_back({1, 1});
    for (int i = 3; i <= n; i++) {
        if (i % 2)
            ans.push_back({i, i - 1});
        else
            ans.push_back({i - 2, i - 1});
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i].first << ' ' << ans[i].second << endl;

    return 0;
}
