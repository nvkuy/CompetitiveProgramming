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

    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<vector<int>> f(n + 1, vector<int>(2, 1e9));
    f[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 0)
            f[i][0] = min(f[i - 1][0] + 1, f[i - 1][1]);
        else if (a[i] == 1) {
            f[i][0] = min(f[i - 1][0] + 1, f[i - 1][1]);
            if (i > 1) f[i][0] = min(f[i][0], min(f[i - 2][0], f[i - 2][1]) + 1);
            if (i > 1 && a[i - 1] != 0) f[i][0] = min(f[i][0], min(f[i - 1][0], f[i - 1][1]));
            f[i][1] = min(f[i - 1][0] + 1, f[i - 1][1]);
        } else {
            f[i][1] = min(f[i - 1][0] + 1, f[i - 1][1]);
            if (i > 1) f[i][1] = min(f[i][1], min(f[i - 2][0], f[i - 2][1]) + 1);
            if (i > 1 && a[i - 1] != 0) f[i][1] = min(f[i][1], min(f[i - 1][0], f[i - 1][1]));
        }
    }

    cout << min(f[n][0], f[n][1]) << endl;

    return 0;
}
