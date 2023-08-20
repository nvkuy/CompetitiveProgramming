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
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        int full_and = a[0];
        for (int i = 0; i < n; i++) full_and &= a[i];
        if (full_and != 0) {
            cout << 1 << endl;
            continue;
        }
        int cur = -1, ans = 0;
        while (a.size() > 0) {
            if (cur == -1) cur = a.back();
            else cur &= a.back();
            a.pop_back();
            if (cur == 0) {
                ans++;
                cur = -1;
            }
        }
        cout << ans << endl;
    }

    return 0;
}