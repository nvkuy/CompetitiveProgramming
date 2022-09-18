#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, x, ai;
    cin >> n >> x;
    map<int, int> dd;
    pair<int, int> ans = {-1, -1};

    for (int i = 0; i < n; i++) {
        cin >> ai;
        if (ans.first > 0)
            continue;
        if (dd.find(x - ai) != dd.end())
            ans = {dd[x - ai], i + 1};
        else
            dd.insert(make_pair(ai, i + 1));
    }
    if (ans.first < 0)
        cout << "IMPOSSIBLE";
    else
        cout << ans.first << ' ' << ans.second;

    return 0;
}
