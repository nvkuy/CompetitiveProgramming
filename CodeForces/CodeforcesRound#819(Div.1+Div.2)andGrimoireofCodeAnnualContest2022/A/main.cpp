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

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n);
        int amax = 1, amin = 999;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            amax = max(amax, a[i]);
            amin = min(amin, a[i]);
        }
        int ans = max(a[n - 1] - amin, amax - a[0]);
        for (int i = 0; i < n; i++) {
            vector<int> na;
            na.push_back(a[n - 1]);
            for (int j = 0; j < n - 1; j++)
                na.push_back(a[j]);
            a = na;
            ans = max(ans, a[n - 1] - a[0]);
        }
        cout << ans << endl;
    }

    return 0;
}
