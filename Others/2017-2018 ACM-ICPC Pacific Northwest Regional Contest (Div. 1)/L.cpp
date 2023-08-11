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

    int k, p, x;
    cin >> k >> p >> x;

    double ans = 2e18;
    for (int i = 1; i <= 1e4 * k; i++) {
        double day = (1.0 * k) / (1.0 * i);
        ans = min(ans, 1.0 * p * day + 1.0 * i * x);
    }

    cout << setprecision(3) << fixed << ans << endl;

    return 0;
}
