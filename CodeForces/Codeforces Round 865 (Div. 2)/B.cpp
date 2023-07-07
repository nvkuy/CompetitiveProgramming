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

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> ans(n, vector<int>(2));
        int j = 2 * n;
        for (int i = 0; i < n; i += 2) {
            ans[i][0] = j--;
            ans[(i - 1 + n) % n][1] = j--;
        }
        for (int i = 1; i < n; i += 2) {
            ans[i][0] = j--;
            ans[(i - 1 + n) % n][1] = j--;
        }
        for (int j = 0; j < 2; j++) {
            for (int i = 0; i < n; i++)
                cout << ans[i][j] << ' ';
            cout << endl;
        }
    }

    return 0;
}
