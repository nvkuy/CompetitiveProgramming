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

    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m)), cntRow(n, vector<int>(26, 0)), cntCol(m, vector<int>(26, 0));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            int tmp = s[j] - 'a';
            a[i][j] = tmp;
            cntRow[i][tmp]++;
            cntCol[j][tmp]++;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int tmp = a[i][j];
            ans += (max(cntCol[j][tmp], cntRow[i][tmp]) == 1);
            // cout << i << ' ' << j << ' ' << cntCol[j][tmp] << ' ' << cntRow[i][tmp] << endl;
        }
    }

    cout << ans << endl;

    return 0;
}
