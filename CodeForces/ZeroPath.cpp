#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int MAXN = 2e3 + 1, zero = 1e3;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> a[i][j];
        vector<bitset<MAXN>> pf(m + 1, bitset<MAXN>(0)), f = pf;
        f[0][zero] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int si = (a[i][j] == 1), so = 1 - si;
                // f[j] |= ((pf[j] << si) >> so);
                // f[j] |= ((f[j - 1] << si) >> so);
                // f[j] = ((pf[j] << si) >> so) | ((f[j - 1] << si) >> so);
                f[j] = ((pf[j] | f[j - 1]) << si) >> so;
            }
            pf = f;
            fill(f.begin(), f.end(), bitset<MAXN>(0));
        }
        cout << (pf[m][zero] ? "YES" : "NO") << endl; 
    }

    return 0;
}
