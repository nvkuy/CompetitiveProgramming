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

    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<vector<int>> c(n, vector<int>(m, 0));
        cin.ignore();
        string s;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            getline(cin, s);
            for (int j = 0; j < m; j++) {
                if (s[j] == '1') {
                    c[i][j] = 1;
                    ans++;
                }
            }
        }
        bool isFree = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((j + 1 < m && c[i][j] + c[i][j + 1] == 0) || (i + 1 < n && c[i][j] + c[i + 1][j] == 0))
                    isFree = true;
                if (i + 1 < n && j + 1 < m && c[i][j] + c[i + 1][j] + c[i][j + 1] + c[i + 1][j + 1] == 2)
                    isFree = true;
            }
        }
        if (!isFree) {
            if (ans == n * m)
                ans -= 2;
            else
                ans--;
        }
        cout << ans << endl;
    }

    return 0;
}
