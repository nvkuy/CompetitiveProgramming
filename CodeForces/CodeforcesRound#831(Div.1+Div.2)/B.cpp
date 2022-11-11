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
        vector<pair<int, int>> a(n);
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i].first >> a[i].second;
            if (a[i].first < a[i].second)
                swap(a[i].first, a[i].second);
            ans += (2 * a[i].second);
        }
        sort(a.begin(), a.end());
        a.push_back({0, 0});
        int pre = 0;
        for (int i = 0; i <= n; i++) {
            ans += abs(a[i].first - pre);
            pre = a[i].first;
        }
        cout << ans << endl;
    }

    return 0;
}
