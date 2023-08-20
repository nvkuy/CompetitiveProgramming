#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'
#define bit_cnt(x) __builtin_popcountll(x)

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> ans(n + 1, vector<int>(m + 1));
        if (n % 2 && m % 2) {
            int tmp = 1;
            for (int i = 1; i <= m; i++) {
                for (int j = n / 2; j >= 1; j--)
                    ans[j][i] = tmp++;
                for (int j = n; j > n / 2 + 1; j--)
                    ans[j][i] = tmp++;
                ans[n / 2 + 1][i] = tmp++;
            }
            vector<vector<int>> realAns(n + 1, vector<int>(m + 1));
            int k = 0;
            for (int i = 1; i <= m; i += 2) {
                k++;
                for (int j = 1; j <= n; j++)
                    realAns[j][k] = ans[j][i];
            }
            for (int i = 2; i <= m; i += 2) {
                k++;
                for (int j = 1; j <= n; j++)
                    realAns[j][k] = ans[j][i];
            }
            ans = realAns;
        } else {
            if (n % 2 == 0) {
                int tmp = 1;
                for (int i = 1; i <= m; i++)
                    for (int j = 1; j <= n; j++)
                        ans[j][i] = tmp++;
            } else {
                int tmp = 1;
                for (int i = 1; i <= n; i++)
                    for (int j = 1; j <= m; j++)
                        ans[i][j] = tmp++;
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++)
                cout << ans[i][j] << ' ';
            cout << endl;
        }
    }

    return 0;
}
