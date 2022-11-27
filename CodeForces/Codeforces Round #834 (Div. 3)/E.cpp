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

    long long t, n, h;
    cin >> t;
    while (t--) {
        cin >> n >> h;
        vector<long long> a(n + 1, 0);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a.begin(), a.end());
        vector<vector<vector<long long>>> f(n + 1, vector<vector<long long>>(3, vector<long long>(2, 0)));
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 2; j++) {
                long long tmp = h;
                int db = 2 - i, tb = 1 - j;
                while (db > 0) {
                    tmp *= 2LL;
                    db--;
                }
                while (tb > 0) {
                    tmp *= 3LL;
                    tb--;
                }
                f[0][i][j] = tmp;
            }
        }
        // cout << "TEST" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 2; k++) {
                    for (int nj = 0; nj <= j; nj++) {
                        for (int nk = 0; nk <= k; nk++) {
                            if (f[i][j][k] <= a[i + 1]) {
                                long long tmp = f[i][j][k];
                                int db = j - nj, tb = k - nk;
                                while (tmp <= a[i + 1] && db > 0) {
                                    tmp *= 2LL;
                                    db--;
                                }
                                while (tmp <= a[i + 1] && tb > 0) {
                                    tmp *= 3LL;
                                    tb--;
                                }
                                if (tmp <= a[i + 1])
                                    continue;
                                tmp += (a[i + 1] / 2);
                                while (db > 0) {
                                    tmp *= 2LL;
                                    db--;
                                }
                                while (tb > 0) {
                                    tmp *= 3LL;
                                    tb--;
                                }
                                f[i + 1][nj][nk] = max(f[i + 1][nj][nk], tmp);
                            } else {
                                long long tmp = f[i][j][k];
                                int db = j - nj, tb = k - nk;
                                tmp += (a[i + 1] / 2);
                                while (db > 0) {
                                    tmp *= 2LL;
                                    db--;
                                }
                                while (tb > 0) {
                                    tmp *= 3LL;
                                    tb--;
                                }
                                f[i + 1][nj][nk] = max(f[i + 1][nj][nk], tmp);
                            }
                        }
                    }
                    // cout << f[i][j][k] << endl;
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
            if (f[i][0][0] != 0)
                ans = i;
        cout << ans << endl;
    }

    return 0;
}
