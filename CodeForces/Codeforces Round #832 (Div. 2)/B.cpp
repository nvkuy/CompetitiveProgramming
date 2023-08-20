#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

inline void debugLocal() {
    if (!fopen("input.txt", "r"))
        return;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> pn, pnn;
        for (int i = 0; i < n; i++) {
            pn.push_back(i * 3 + 3);
            pnn.push_back(i * 3 + 1);
        }
        vector<pair<int, int>> ans;
        reverse(pnn.begin(), pnn.end());
        while (pn.size() > 0 && pn.back() > pnn.back()) {
            ans.push_back({pn.back(), pnn.back()});
            pn.pop_back();
            pnn.pop_back();
        }
        cout << ans.size() << endl;
        for (auto p : ans)
            cout << p.first << ' ' << p.second << endl;
    }

    return 0;
}