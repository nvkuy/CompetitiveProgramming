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

    int t, n;
    string s1, s2;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> s1;
        cin >> s2;
        vector<vector<int>> f(n + 1, vector<int>(2, 0));
        f[0][0] = f[0][1] = 1;
        for (int i = 1; i <= n; i++) {
            if (s1[i - 1] == 'B' && s2[i - 1] == 'B') {
                f[i][0] = f[i - 1][1];
                f[i][1] = f[i - 1][0];
            } else {
                if (s1[i - 1] == 'B')
                    f[i][0] = f[i - 1][0];
                else
                    f[i][1] = f[i - 1][1];
            }
        }
        cout << (max(f[n][1], f[n][0]) ? "YES" : "NO") << endl;
    }

    return 0;
}
