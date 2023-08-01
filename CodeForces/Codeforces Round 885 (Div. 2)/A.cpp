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

    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        int x, y, catch_able = 0;
        cin >> x >> y;
        while (k--) {
            int tx, ty;
            cin >> tx >> ty;
            if ((abs(x - tx) + abs(y - ty)) % 2 == 0)
                catch_able = 1;
        }
        cout << (catch_able == 0 ? "YES" : "NO") << endl;
    }

    return 0;
}
