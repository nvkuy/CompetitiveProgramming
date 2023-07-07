#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

bool cmp(const pair<int, int> &p1, const pair<int, int> &p2) {
    return p1.second < p2.second;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<pair<int, int>> range(n), all_pair;
        for (int i = 0; i < n; i++)
            cin >> range[i].first >> range[i].second;
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (i == j || range[i].second < range[j].first || range[i].first > range[j].second)
                    continue;
                all_pair.push_back({min(range[i].first, range[j].first), max(range[i].second, range[j].second)});
            }
        }

        sort(all_pair.begin(), all_pair.end(), cmp);
        int ans = 0, lastBusy = -1;
        for (auto p : all_pair) {
            // cout << p.first << '|' << p.second << endl;
            if (p.first > lastBusy) {
                ans++;
                lastBusy = p.second;
            }
        }

        cout << n - 2 * ans << endl;

    }

    return 0;
}
