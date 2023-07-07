#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

inline void debugLocal() {
    if (!fopen("input.txt", "r"))
        return;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

const double len_road = 100, len_turtle = 10, eps = 1e-9;

bool cmpLess(double d1, double d2) {
    return d1 + eps < d2;
}

bool cmpEqual(double d1, double d2) {
    return abs(d1 - d2) < eps;
}

bool canFinish(double time, double t, double s) {
    double dis_s = s * time;
    if (cmpLess(len_turtle, dis_s)) dis_s = 10;
    double dis_t = t * time;
    if (cmpLess(dis_t, len_road - dis_s)) return false;
    return true;
}

double findTimeFinish(double t, double s) {
    double l = 0, r = 200, m;
    while (cmpLess(l, r)) {
        m = (l + r) / 2;
        if (canFinish(m, t, s)) r = m;
        else l = m + eps;
    }
    return r;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    //debugLocal();

    int t;
    cin >> t;
    while (t--) {
        int t1, s1, t2, s2;
        cin >> t1 >> s1 >> t2 >> s2;
        double tf1 = findTimeFinish(t1, s1), tf2 = findTimeFinish(t2, s2);
        if (cmpEqual(tf1, tf2)) {
            cout << "Draw" << endl;
            continue;
        }
        if (cmpLess(tf1, tf2)) {
            cout << "Megumin" << endl;
            continue;
        }
        cout << "Yunyun" << endl;
    }

    return 0;
}
