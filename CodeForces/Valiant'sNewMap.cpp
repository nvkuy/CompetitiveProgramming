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

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> a[i][j];
        int l = 1, r = min(n, m);
        while (l < r) {
            long long x = (l + r + 1) / 2;
            vector<vector<long long>> ps(n + 1, vector<long long>(m + 1, 0));
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= m; j++)
                    ps[i][j] = ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1] + (a[i][j] >= x);
            bool iok = false;
            for (int i = x; i <= n; i++)
                for (int j = x; j <= m; j++)
                    iok |= (ps[i][j] - ps[i - x][j] - ps[i][j - x] + ps[i - x][j - x] == x * x);
            if (iok)
                l = x;
            else
                r = x - 1;
        }
        cout << l << endl;
    }

    return 0;
}
