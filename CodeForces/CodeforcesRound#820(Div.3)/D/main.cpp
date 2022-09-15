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
        vector<int> x(n), y(n);
        for (int i = 0; i < n; i++)
            cin >> x[i];
        for (int i = 0; i < n; i++)
            cin >> y[i];
        vector<int> a;
        for (int i = 0; i < n; i++)
            a.push_back(y[i] - x[i]);
        sort(a.begin(), a.end());
        int ans = 0, i1 = 0, i2 = n - 1;
        while (i1 < i2) {
            if (a[i1] + a[i2] >= 0) {
                ans++;
                i1++, i2--;
                continue;
            }
            i1++;
        }
        cout << ans << endl;
    }

    return 0;
}
