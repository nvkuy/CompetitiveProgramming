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

    int t, n, ai, c;
    cin >> t;
    while (t--) {
        cin >> n >> c;
        map<int, int> cnt;
        for (int i = 0; i < n; i++) {
            cin >> ai;
            cnt[ai]++;
        }
        long long ans = 0;
        for (auto p : cnt) {
            if (p.second > c)
                ans += c;
            else
                ans += p.second;
        }
        cout << ans << endl;
    }

    return 0;
}