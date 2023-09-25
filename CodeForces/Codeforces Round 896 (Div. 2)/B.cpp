#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'
#define bit_cnt(x) __builtin_popcountll(x)

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

long long dist(const pair<long long, long long> &p1, const pair<long long, long long> &p2) {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, k, a, b;
        cin >> n >> k >> a >> b;
        vector<pair<long long, long long>> c(n + 1);
        for (int i = 1; i <= n; i++) {
            int x, y;
            cin >> x >> y;
            c[i] = {x, y};
        }
        long long ans = dist(c[a], c[b]);
        long long da = 1e18, db = 1e18;
        for (int i = 1; i <= k; i++) {
            da = min(da, dist(c[a], c[i]));
            db = min(db, dist(c[b], c[i]));
        }
        ans = min(ans, da + db);
        cout << ans << endl;
    }

    return 0;
}
