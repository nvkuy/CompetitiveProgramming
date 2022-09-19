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

    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        long long ans = 0;
        for (int i = n - 1; n - i <= k; i--) {
            int maxPos = a[i];
            int pos = i;
            while (pos >= 0) {
                maxPos = max(maxPos, a[pos]);
                pos -= k;
            }
            a[i] = maxPos;
            ans += a[i];
        }
        cout << ans << endl;
    }

    return 0;
}