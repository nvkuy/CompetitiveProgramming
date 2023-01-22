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
        int cs = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            cs += a[i];
            cs %= 2;
        }
        if (cs % 2 == 0) {
            cout << 0 << endl;
            continue;
        }
        int ans = 1e9;
        for (int i = 0; i < n; i++) {
            int tans = 0;
            if (a[i] % 2) {
                while (a[i] % 2) {
                    a[i] /= 2;
                    tans++;
                }
            } else {
                while (a[i] % 2 == 0) {
                    a[i] /= 2;
                    tans++;
                }
            }
            ans = min(ans, tans);
        }
        cout << ans << endl;
    }

    return 0;
}
