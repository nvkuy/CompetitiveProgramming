#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        int ans = a[n - 1];
        for (int i = 0; i < n; i++) {
            int l = a[i], r = 1e9, m;
            while (l < r) {
                int m = (l + r + 1) / 2;
                bool iok = false;
                int val = m, rm = k;
                for (int j = i; j < n; j++) {
                    if (a[j] >= val) {
                        iok = true;
                        break;
                    }
                    if (rm < val - a[j]) break;
                    rm -= (val - a[j]);
                    val--;
                }
                if (iok)
                    l = m;
                else
                    r = m - 1;
            }
            ans = max(ans, l);
        }
        cout << ans << endl;
    }

    return 0;
}
