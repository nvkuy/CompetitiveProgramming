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

    int t, n, m, x, y, d;
    cin >> t;
    while (t--) {
        cin >> n >> m >> x >> y >> d;
        if ((n - x <= d && m - y <= d) || (x - 1 <= d && y - 1 <= d) || (x - 1 <= d && n - x <= d) || (y - 1 <= d && m - y <= d))
            cout << -1;
        else
            cout << n + m - 2;
        cout << endl;
    }

    return 0;
}
