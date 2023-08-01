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

    int n, m;
    cin >> n >> m;
    vector<vector<int>> c(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> c[i][j];
    int l = 0, r = 1e9 + 7;
    pair<int, int> ans;
    while (l < r) {
        int mm = (l + r + 1) / 2;
        vector<int> mask_pos(1 << m, -1);
        for (int i = 0; i < n; i++) {
            int num = 0;
            for (int j = 0; j < m; j++)
                num ^= ((c[i][j] >= mm) << j);
            mask_pos[num] = i;
        }
        bool iok = false;
        for (int i = 0; i < (1 << m); i++) {
            if (iok) break;
            for (int j = 0; j < (1 << m); j++) {
                if ((i | j) == (1 << m) - 1 && mask_pos[i] >= 0 && mask_pos[j] >= 0) {
                    iok = true;
                    ans = {mask_pos[i], mask_pos[j]};
                    break;
                }
            }
        }
        if (iok)
            l = mm;
        else
            r = mm - 1;
    }

    cout << ans.first + 1 << ' ' << ans.second + 1 << endl;

    return 0;
}
