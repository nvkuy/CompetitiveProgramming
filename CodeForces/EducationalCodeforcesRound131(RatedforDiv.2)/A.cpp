#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

inline void debugMode() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugMode();

    int t;
    cin >> t;
    while (t--) {
        vector<vector<int>> c(2, vector<int>(2));
        cin >> c[0][0] >> c[0][1] >> c[1][0] >> c[1][1];
        int tmp = c[0][0] + c[0][1] + c[1][0] + c[1][1];
        if (tmp == 0) {
            cout << 0 << endl;
            continue;
        }
        if (tmp == 4) {
            cout << 2 << endl;
            continue;
        }
        cout << 1 << endl;
    }

    return 0;
}
