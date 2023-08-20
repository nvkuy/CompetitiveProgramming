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

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> zero(n + m + 1, 0);
        vector<vector<int>> event(n + m + 1);
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            event[a[i]].push_back(0);
        }
        for (int i = 1; i <= m; i++) {
            int p, v;
            cin >> p >> v;
            p--;
            event[a[p]].push_back(i);
            event[v].push_back(i);
            a[p] = v;
        }
        for (int i = 0; i <= n + m; i++) {
            int start = 0, has = false;
            for (int time : event[i]) {
                if (!has) zero[i] += time - start;
                start = time;
                has = !has;
            }
            if (!has) zero[i] += m - start + 1;
        }
        long long ans = 0;
        for (int i = 0; i <= n + m; i++) {
            long long not_zero = m + 1 - zero[i];
            ans += not_zero * zero[i];
            ans += (not_zero * (not_zero - 1)) / 2LL;
            // cout << "@i: " << i << ' ' << not_zero << ' ' << zero[i] << endl;
        }
        cout << ans << endl;
    }

    return 0;
}
