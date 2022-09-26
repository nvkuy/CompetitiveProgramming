#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("in", "r", stdin);

    int t, n, k, ai;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<long long> a(n + 2, 1e18);
        for (int i = 1; i <= n; i++) {
            cin >> ai;
            a[i] = ai;
        }
        long long h = 0, mh = 0;
        vector<pair<long long, long long>> goodLeft, goodRight;
        for (int i = k + 1; i <= n + 1; i++) {
            h += a[i];
            mh = min(mh, h);
            if (h >= 0) {
                goodRight.push_back({h, -mh});
                h = mh = 0;
            }
        }
        for (int i = k - 1; i >= 0; i--) {
            h += a[i];
            mh = min(mh, h);
            if (h >= 0) {
                goodLeft.push_back({h, -mh});
                h = mh = 0;
            }
        }
        reverse(goodLeft.begin(), goodLeft.end());
        reverse(goodRight.begin(), goodRight.end());
        // for (int i = 0; i < goodLeft.size(); i++)
        //     cout << goodLeft[i].first << '|' << goodLeft[i].second << ' ';
        // cout << endl;
        // for (int i = 0; i < goodRight.size(); i++)
        //     cout << goodRight[i].first << '|' << goodRight[i].second << ' ';
        // cout << endl;
        h = a[k];
        while (true) {
            if (goodLeft.size() == 0 || goodRight.size() == 0)
                break;
            if (h >= goodLeft.back().second) {
                h += goodLeft.back().first;
                goodLeft.pop_back();
                continue;
            }
            if (h >= goodRight.back().second) {
                h += goodRight.back().first;
                goodRight.pop_back();
                continue;
            }
            break;
        }
        // cout << goodLeft.size() << '|' << goodRight.size() << endl;
        cout << (min(goodLeft.size(), goodRight.size()) == 0 ? "YES" : "NO") << endl;
    }

    return 0;
}