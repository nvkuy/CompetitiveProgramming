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

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> a(n);
        multiset<int> s2;
        multiset<pair<int, int>> s1;
        for (int i = 0; i < n; i++) {
            cin >> a[i].first >> a[i].second;
            s2.insert(a[i].second);
        }
        sort(a.begin(), a.end());
        int ans = 1e9 + 7;
        for (int i = 0; i < n; i++) {
            s2.erase(s2.lower_bound(a[i].second));
            s1.insert({a[i].second, a[i].first});
            if (i + 1 < n && a[i].first == a[i + 1].first) continue;
            bool two_max = false;
            if (i - 1 >= 0 && a[i].first == a[i - 1].first) two_max = true;
            int atleast = -1e9 - 7;
            if (s2.size() > 0)
                atleast = *s2.rbegin();
            ans = min(ans, abs(atleast - a[i].first));
            vector<pair<int, int>> available;
            auto it = s1.lower_bound({a[i].first, -1e9});
            if (it == s1.end())
                it--;
            available.push_back(*it);
            if (it != s1.begin())
                it--;
            if (it != s1.end())
                available.push_back(*it);
            if (it != s1.begin())
                it--;
            if (it != s1.end())
                available.push_back(*it);
            it = s1.lower_bound({a[i].first, -1e9});
            if (it != s1.end())
                it++;
            if (it != s1.end())
                available.push_back(*it);
            if (it != s1.end())
                it++;
            if (it != s1.end())
                available.push_back(*it);
            for (auto p : available) {
                if ((p.first <= atleast) || (p.second == a[i].first && !two_max)) continue;
                ans = min(ans, abs(p.first - a[i].first));
            }
        }
        cout << ans << endl;
    }

    return 0;
}
