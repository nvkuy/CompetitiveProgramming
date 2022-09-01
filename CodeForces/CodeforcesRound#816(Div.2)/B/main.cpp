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

    long long t, n, k, b, s;
    cin >> t;
    while (t--) {
        cin >> n >> k >> b >> s;
        vector<long long> ans(n, 0);
        ans[0] = b * k;
        s -= ans[0];
        for (int i = 0; i < n; i++) {
            if (s <= 0)
                break;
            long long tmp = min(s, k - 1);
            s -= tmp;
            ans[i] += tmp;
        }
        if (s != 0) {
            cout << -1 << endl;
            continue;
        }
        for (int i = 0; i < n; i++)
            cout << ans[i] << ' ';
        cout << endl;
    }

    return 0;
}
