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

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<string> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        vector<bool> rm(n, 1);
        for (int i = 0; i < k; i++) {
            for (int j = 1; j < n; j++) {
                if (a[j][i] != a[0][i])
                    rm[j] = 0;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) ans += rm[i];
        cout << ans << endl;
    }

    return 0;
}
