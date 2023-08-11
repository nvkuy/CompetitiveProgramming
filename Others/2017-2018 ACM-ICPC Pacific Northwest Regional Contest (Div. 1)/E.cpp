#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const double eps = 1e-12;

double move(const pair<double, double> &speed, pair<double, double> &pos, double dist) {
    double need_time = dist / speed.first;
    pos.first += need_time * speed.first;
    pos.second += need_time * speed.second;
    return need_time;
}

struct side_walk {
    double l, r, v;
};

double n, x, v;
vector<side_walk> sw;

pair<double, double> cal(double eg) {
    double tans = 0;
    pair<double, double> pos = {0, 0}, speed = {v * cos(eg), v * sin(eg)};
    for (auto tsw : sw) {
        tans += move(speed, pos, abs(tsw.l - pos.first));
        tans += move({speed.first, speed.second + tsw.v}, pos, abs(tsw.r - pos.first));
    }
    tans += move(speed, pos, abs(x - pos.first));
    return {abs(pos.second), tans};
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cout << setprecision(3) << fixed;

    cin >> n >> x >> v;
    sw.resize(n);
    for (int i = 0; i < n; i++)
        cin >> sw[i].l >> sw[i].r >> sw[i].v;
    
    double l = -M_PI_2 + eps, r = M_PI_2 - eps;
    while (l + eps < r) {
        // cout << "@test: " << l << ' ' << r << endl;
        double x1 = l + (r - l) / 3.0, x2 = l + (r - l) * 2.0 / 3.0;
        if (cal(x1).first < cal(x2).first)
            r = x2 - eps;
        else
            l = x1 + eps;
    }

    double ans = cal(l).second;
    if (ans > ((2.0  * x) / (1.0 * v))) {
        cout << "Too hard" << endl;
        return 0;
    }
    cout << ans << endl;

    return 0;
}
