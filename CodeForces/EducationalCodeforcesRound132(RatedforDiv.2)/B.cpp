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

    int n, m, x, y;
    cin >> n >> m;
    vector<int> a(n);
    vector<vector<long long>> f(2, vector<long long>(n + 1, 0));
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++) {
        f[0][i] = f[0][i - 1];
        f[1][i] = f[1][i - 1];
        if (i - 2 >= 0)
            f[0][i] += max(0, a[i - 2] - a[i - 1]);
        if (i - 2 >= 0)
            f[1][i] += max(0, a[i - 1] - a[i - 2]);
    }
    // cout << "@" << endl;
    // for (int i = 0; i <= n; i++)
    //     cout << f[0][i] << ' ';
    // cout << endl;
    // for (int i = 0; i <= n; i++)
    //     cout << f[1][i] << ' ';
    // cout << endl;
    while (m--) {
        cin >> x >> y;
        int first = 0, second = 1;
        if (x > y) {
            swap(first, second);
            swap(x, y);
        }
        cout << f[first][y] - f[first][x] << endl;
    }

    return 0;
}