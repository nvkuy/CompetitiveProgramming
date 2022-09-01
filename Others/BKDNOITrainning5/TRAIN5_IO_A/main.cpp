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

    int t, a, b;
    cin >> t;
    int p1 = 0, p2 = 0;
    while (t--) {
        cin >> a >> b;
        if (a == b) {
            p1 += a;
            p2 += a;
            continue;
        }
        if (a > b)
            p1 += (a + b);
        else
            p2 += (a + b);
    }
    cout << p1 << ' ' << p2;

    return 0;
}
