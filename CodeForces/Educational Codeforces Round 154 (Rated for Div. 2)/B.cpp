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
        string a, b;
        cin >> a >> b;
        int n = a.length();
        vector<vector<int>> f(n + 1, vector<int>(2, 0));
        f[0][1] = f[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            if (a[i - 1] != b[i - 1]) continue;
            if (a[i - 1] == '1') {
                for (int j = 1; j <= i; j++) {
                    if (a[j - 1] == '1' && b[j - 1] == '1')
                        f[i][1] |= (f[j - 1][0] | f[j - 1][1]);
                }
            } else {
                for (int j = 1; j <= i; j++) {
                    if (a[j - 1] == '0' && b[j - 1] == '0')
                        f[i][0] |= (f[j - 1][0] | f[j - 1][1]);
                }
            }
        }
        cout << ((f[n][0] | f[n][1]) ? "YES" : "NO") << endl;
    }

    return 0;
}
