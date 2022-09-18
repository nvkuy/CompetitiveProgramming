#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

bool cmp(pair<int, int> p1, pair<int, int> p2) {
    if (p1.first == p2.first)
        return p1.second < p2.second;
    return p1.first < p2.first;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n, x, y;
    cin >> t;
    while (t--) {
        cin >> n;
        int ans = 0, curX = 0, curY = 0;
        vector<pair<int, int>> boxs(n);
        for (int i = 0; i < n; i++)
            cin >> boxs[i].first >> boxs[i].second;
        sort(boxs.begin(), boxs.end(), cmp);
        for (pair<int, int> p : boxs) {
            ans += abs(p.first - curX) + abs(p.second - curY);
            curX = p.first, curY = p.second;
        }
        ans += abs(curX) + abs(curY);
        cout << ans << endl;
    }

    return 0;
}
