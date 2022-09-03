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

    int t, n, k, r, c;
    cin >> t;
    while (t--) {
        cin >> n >> k >> r >> c;
        vector<vector<char>> ans(n + 1, vector<char>(n + 1, '.'));
        vector<int> start(n + 1, 0);
        while (true) {
            if (start[r] != 0)
                break;
            while (c - k > 0)
                c -= k;
            start[r] = c;
            r++, c++;
            if (r > n)
                r = 1;
            if (c > n)
                c = 1;
        }
        for (int i = 1; i <= n; i++) {
            int j = start[i];
            while (j <= n) {
                ans[i][j] = 'X';
                j += k;
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++)
                cout << ans[i][j];
            cout << endl;
        }
    }

    return 0;
}
