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
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        map<long long, int> cnt;
        long long curs = 0;
        int ans = 0, max_cnt = 0, i = 1;
        for (; i <= n; i++) {
            if (a[i] == 0)
                break;
            curs += a[i];
            if (curs == 0) ans++;
        }
        for (; i <= n; i++) {
            if (a[i] == 0) {
                cnt.clear();
                cnt[curs]++;
                ans += max_cnt;
                max_cnt = 1;
                continue;
            }
            curs += a[i];
            cnt[curs]++;
            max_cnt = max(max_cnt, cnt[curs]);
        }
        ans += max_cnt;
        cout << ans << endl;
    }

    return 0;
}
