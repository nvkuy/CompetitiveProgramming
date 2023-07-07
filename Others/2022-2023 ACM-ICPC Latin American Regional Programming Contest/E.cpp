#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

set<int> used;

int solveFor(int x) {
    for (int cost = 0; cost < 4; cost++) {
        for (int i = 0; i <= x; i++) {
            int a = i, b = x - cost - i;
            if (a < 0 || b < 0 || a == b) continue;
            if (a > 0 && used.count(a) > 0) continue;
            if (b > 0 && used.count(b) > 0) continue;
            used.insert(a);
            used.insert(b);
            // cout << x << ' ' << a << ' ' << b << endl;
            return cost;
        }
    }
    return x;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, a, b;
    cin >> n >> a >> b;
    int sp1 = b, sp2 = n - a - b;
    if (sp1 > sp2) swap(sp1, sp2);
    used.insert(a);
    cout << solveFor(sp1) + solveFor(sp2) << endl;

    return 0;
}
