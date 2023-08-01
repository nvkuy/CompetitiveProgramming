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

    int tt;
    cin >> tt;
    while (tt--) {
        long long h, c, t;
        cin >> h >> c >> t;
        if (t * 2 <= h + c) {
            cout << 2 << endl;
            continue;
        }
        long long l = 1, r = 1e12 + 3, m;
        while (l < r) {
            m = (l + r + 1) / 2;
            if (t * (m * 2 - 1) <= m * h + (m - 1) * c)
                l = m;
            else
                r = m - 1;
        }
        assert(l <= 1e6);
        if (abs(t * (l * 2 - 1) - (l * h + (l - 1) * c)) * (l * 2 + 1) > abs(t * ((l + 1) * 2 - 1) - ((l + 1) * h + l * c)) * (l * 2 - 1))
            cout << l * 2 + 1 << endl;
        else
            cout << l * 2 - 1 << endl;
    }

    return 0;
}
