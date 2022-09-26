#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, le<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const double er = 1e-7;

bool le(double a, double b) {
    return (b - a > er);
}

bool gr(double a, double b) {
    return (a - b > er);
}

bool eq(double a, double b) {
    return (abs(a - b) < er);
}

double check(double time, vector<int> &x, vector<int> &t) {
    double l = 0, r = 1e8;
    for (int i = 0; i < x.size(); i++) {
        if (gr(l, r) || le(time, t[i]))
            return 1e9;
        double tmp = time - t[i];
        double ll = x[i] - tmp, rr = x[i] + tmp;
        if (gr(ll, r) || le(rr, l))
            return 1e9;
        l = max(l, ll);
        r = min(r, rr);
    }
    if (gr(l, r))
        return 1e9;
    return l;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int tt, n;
    cin >> tt;
    cout << setprecision(8) << fixed;
    while (tt--) {
        cin >> n;
        vector<int> x(n), t(n);
        for (int i = 0; i < n; i++)
            cin >> x[i];
        for (int i = 0; i < n; i++)
            cin >> t[i];
        double l = 0, r = 1e9, m;
        while (true) {
            if (eq(l, r) || gr(l, r))
                break;
            //cout << l << ' ' << r << endl;
            m = (l + r) / 2.0;
            if (gr(check(m, x, t), 1e8))
                l = m + er;
            else
                r = m;
        }
        cout << check(r, x, t) << endl;
    }

    return 0;
}