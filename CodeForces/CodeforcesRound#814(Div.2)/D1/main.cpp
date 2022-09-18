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
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        vector<vector<int>> f(n, vector<int>(1 << 13));
        fill(f[0].begin(), f[0].end(), 1);
        f[0][a[0]] = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < (1 << 13); j++) {
                f[i][j] = f[i - 1][0] + (a[i] != j);
                int need = (j ^ a[i]);
                f[i][j] = min(f[i][j], f[i - 1][need] + 1);
            }
        }
        cout << f[n - 1][0] << endl;
        /*
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 6; j++)
                cout << f[i][j] << ' ';
            cout << endl;
        }
        */
    }

    return 0;
}
