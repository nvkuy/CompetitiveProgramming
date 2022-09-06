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
        vector<int> ans(n, -1);
        for (int i = n - 1; i >= 0; i--) {
            if (ans[i] >= 0)
                continue;
            for (int j = sqrt(2 * i); j >= 0; j--) {
                int num = j * j - i;
                if (ans[num] >= 0)
                    continue;
                ans[i] = num;
                ans[num] = i;
                break;
            }
            if (ans[i] < 0)
                break;
        }
        if (ans[0] < 0) {
            cout << -1 << endl;
            continue;
        }
        for (int i = 0; i < n; i++)
            cout << ans[i] << ' ';
        cout << endl;
    }

    return 0;
}
