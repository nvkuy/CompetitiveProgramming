#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n), two_cnt(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        two_cnt[i + 1] += (two_cnt[i] + (a[i] == 2));
    }
    vector<pair<int, int>> range;
    int curL = -1;
    for (int i = 0; i < n; i++) {
        if (curL < 0 && a[i] == 0) continue;
        if (curL < 0) curL = i;
        if (i + 1 == n || a[i + 1] == 0) {
            if (curL >= 0)
                range.push_back({curL, i});
            curL = -1;
        }
    }
    vector<int> rm(n, 0);
    int ans = range.size(), del = 0;
    for (auto p : range) {
        del += (p.second - p.first + 1);
        if (p.first > 0 && a[p.first] > 0 && rm[p.first - 1] == 0) {
            rm[p.first - 1] = 1;
            a[p.first]--;
            ans--;
        }
        if (a[p.first] == 0 && two_cnt[p.second + 1] - two_cnt[p.first] == 0)
            a[p.second]--;
        if (p.second + 1 < n && a[p.second] > 0 && rm[p.second + 1] == 0) {
            rm[p.second + 1] = 1;
            a[p.second]--;
            ans--;
        }
    }
    ans += (n - del);
    cout << ans << endl;

    return 0;
}
