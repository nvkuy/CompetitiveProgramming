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
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int curXor = 0, ans = n;
        set<int> px;
        for (int i = 0; i < n; i++) {
            curXor ^= a[i];
            if (curXor == 0 || a[i] == 0 || px.find(curXor) != px.end()) {
                px.clear();
                ans--;
                curXor = 0;
            } else
                px.insert(curXor);
        }
        cout << ans << endl;
    }

    return 0;
}
