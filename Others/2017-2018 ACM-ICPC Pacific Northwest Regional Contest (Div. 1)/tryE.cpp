#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const double eps = 1e-4;

struct side_walk {
    int l, r;
    double v;
};

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cout << setprecision(3) << fixed;

    int n, x;
    double v, sum_seg = 0;
    cin >> n >> x >> v;
    vector<side_walk> sw(n);
    for (int i = 0; i < n; i++) {
        cin >> sw[i].l >> sw[i].r >> sw[i].v;
        sum_seg += sw[i].r - sw[i].l;
    }
        
    double ans = 1e18;
    for (double x_v = eps; x_v < v; x_v += eps) {
        double sum_dy = 0;
        for (auto tsw : sw)
            sum_dy += tsw.v * (tsw.r - tsw.l) / x_v;
        double y_v = -sum_dy / (x - sum_seg);
        // cout << "@test: " << abs(x_v * x_v + y_v * y_v - v) << endl;
        if (abs(x_v * x_v + y_v * y_v - v) < eps * x)
            ans = min(ans, 1.0 * x / x_v);
    }

    if (ans > ((2.0 * x) / (1.0 * v))) {
        cout << "Too hard" << endl;
        return 0;
    }
    cout << ans << endl;

    return 0;
}
