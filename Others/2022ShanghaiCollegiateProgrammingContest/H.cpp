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

    int n, m, k, t;
    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        vector<pair<int, int>> seg;
        for (int i = 0; i < n; i++) {
            if (seg.size() == 0 || a[i] != seg.back().first)
                seg.push_back({a[i], 1});
            else
                seg.back().second++;
        }
        if (seg.front().first == seg.back().first && seg.size() > 1) {
            seg.front().second += seg.back().second;
            seg.pop_back();
        }
        int ans = 0, valid = 0;
        for (auto p : seg) {
            if (p.second >= k)
                valid = 1;
            ans += ((p.second + k - 1) / k);
        }
        if (valid == 0) {
            cout << -1 << endl;
            continue;
        }
        cout << ans << endl;
    }

    return 0;
}
