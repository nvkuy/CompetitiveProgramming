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
        vector<int> a(n + 1, 0), ans;
        if ((n - 2) % 2 == 0) {
            for (int i = n - 2; i > 0; i--) {
                ans.push_back(i);
                a[i] = 1;
            }
        } else {
            ans.push_back(n - 1);
            a[n - 1] = 1;
            for (int i = n - 3; i > 1; i--) {
                ans.push_back(i);
                a[i] = 1;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (a[i] == 0)
                ans.push_back(i);
        }
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << ' ';
        cout << endl;
    }

    return 0;
}
