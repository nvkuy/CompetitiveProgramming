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
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int mood1 = 0, mood2 = 0;
        mood1 = mood2 = a;
        int ans = a;
        if (max(mood1, mood2) > 0) {
            int tmp = min(b, c);
            ans += 2 * tmp;
            b -= tmp;
            c -= tmp;
        } else
            b = 1, c = 0;
        if (b > 0) {
            int tmp = min(mood2 + 1, b);
            mood2 -= tmp;
            b -= tmp;
            ans += tmp;
        }
        if (c > 0) {
            int tmp = min(mood1 + 1, c);
            mood1 -= tmp;
            c -= tmp;
            ans += tmp;
        }
        if (min(mood1, mood2) >= 0)
            ans += min(min(mood1, mood2) + 1, d);
        cout << ans << endl;
    }

    return 0;
}
