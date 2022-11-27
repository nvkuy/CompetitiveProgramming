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

    int t, l, r, x, a, b;
    cin >> t;
    while (t--) {
        cin >> l >> r >> x >> a >> b;
        int ans = -1;
        if ((abs(r - a) >= x && abs(r - l) >= x && abs(b - l) >= x) || (abs(l - a) >= x && abs(r - l) >= x && abs(b - r) >= x))
            ans = 3;
        if ((abs(r - a) >= x && abs(r - b) >= x) || (abs(l - a) >= x && abs(l - b) >= x))
            ans = 2;
        if (abs(a - b) >= x)
            ans = 1;
        if (a == b)
            ans = 0;
        cout << ans << endl;
    }

    return 0;
}
