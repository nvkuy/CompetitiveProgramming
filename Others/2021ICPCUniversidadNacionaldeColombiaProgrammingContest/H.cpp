#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const double er = 1e-8;

int eq(double x, double y) {
    return abs(x-y) < er;
}

double timeMeet(double p1, double v1, double p2, double v2, double d, double rm) {
    double tmp = min(abs(p2 - p1) / abs(v1 - v2), rm);
    if (p2 + v2 * tmp > d + er)
        return min(abs(d - p1) / v1, rm);
    return tmp;
}

void go(double time, double &p, double &v) {
    p += (time * v);
}

int main()
{
    //freopen("in", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    double d, v1, v2, v3, t;
    double p1 = 0, p2 = 1, p3 = 0;
    cin >> d >> v1 >> v2 >> v3 >> t;
    double rm = t;
    while (true) {
        if (rm < er || (d - p1 < er && d - p2 < er))
            break;
        double tmp = timeMeet(p3, v3, p2, v2, d, rm);
        go(tmp, p1, v1);
        go(tmp, p2, v2);
        go(tmp, p3, v3);

        //cout << rm << ' ' << p3 << ' ' << p2 << endl;
        //assert( eq(p3, p2) || eq(p3, p1) );

        v3 *= -1;
        rm -= tmp; //todo
        swap(p1, p2);
        swap(v1, v2);
    }
    cout << setprecision(8) << fixed << p3 << endl;

    return 0;
}