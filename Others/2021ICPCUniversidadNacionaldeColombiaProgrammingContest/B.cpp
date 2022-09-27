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

    // freopen("in", "r", stdin);

    int n, m, w, u, v;
    while (cin >> n >> m) {
        long long ans = 1;
        while (m--) {
            cin >> w >> u >> v;
            if (w % 2 == 0 || u > n || v > n)
                continue;
            ans *= (long long)(w);
        }
        cout << ans << endl;
    }

    return 0;
}