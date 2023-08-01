#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long n, w1, w2;
    cin >> n >> w1 >> w2;
    vector<long long> a(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<vector<long long>> f(n + 1, vector<long long>(6, -1e16));
    for (int i = 0; i <= n; i++)
        f[i][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 5; j++) {
            f[i][j] = f[i - 1][j];
            if (j == 1)
                f[i][j] = max(f[i][j], f[i - 1][j - 1] + w1 * a[i]);
            else if (j == 2)
                f[i][j] = max(f[i][j], f[i - 1][j - 1] + w2 * a[i]);
            else if (j == 3)
                f[i][j] = max(f[i][j], f[i - 1][j - 1] + a[i]);
            else if (j == 4)
                f[i][j] = max(f[i][j], f[i - 1][j - 1] + w2 * a[i]);
            else
                f[i][j] = max(f[i][j], f[i - 1][j - 1] + w1 * a[i]);
        }
    }

    cout << f[n][5] << endl;

    return 0;
}
