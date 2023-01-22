#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int minToWall(int x, int y, int w, int d) {
    int ans = 1e9;
    ans = min(ans, x);
    ans = min(ans, w - x);
    ans = min(ans, y);
    ans = min(ans, d - y);
    return ans;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int w, d, h;
        int x1, y1, x2, y2;
        cin >> w >> d >> h;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << abs(x1 - x2) + abs(y1 - y2) + h + 2 * min(minToWall(x1, y1, w, d), minToWall(x2, y2, w, d)) << endl;
    }

    return 0;
}
