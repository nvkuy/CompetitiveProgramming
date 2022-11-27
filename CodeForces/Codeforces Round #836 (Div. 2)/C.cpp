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

    int t, n, x;
    cin >> t;
    while(t--) {
        cin >> n >> x;
        if (n % x > 0) {
            cout << -1 << endl;
            continue;
        }
        vector<int> ans(n + 1);
        for (int i = 1; i <= n; i++)
            ans[i] = i;
        ans[1] = x, ans[n] = 1;
        if (x != n)
            ans[x] = n;
        int p = x;
        for (int i = x + 1; i < n; i++) {
            if (ans[i] % p == 0 && ans[p] % i == 0) {
                swap(ans[i], ans[p]);
                p = i;
            }
        }
        for (int i = 1; i <= n; i++)
            cout << ans[i] << ' ';
        cout << endl;
    }

    return 0;
}
