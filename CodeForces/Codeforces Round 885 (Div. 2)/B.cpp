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
        int n, k;
        cin >> n >> k;
        vector<vector<int>> color_pos(k + 1, vector<int>(1, 1));
        for (int i = 1; i <= n; i++) {
            int ci;
            cin >> ci;
            color_pos[ci].push_back(i);
        }
        for (int i = 1; i <= k; i++)
            color_pos[i].push_back(n);
        int l = 0, r = n, m;
        while (l < r) {
            m = (l + r) / 2;
            bool iok = false;
            for (int i = 1; i <= k; i++) {
                bool canPaint = true, cur_ok = true;
                for (int j = 1; j < color_pos[i].size(); j++) {
                    int step = color_pos[i][j] - color_pos[i][j - 1] - 1;
                    if (j + 1 == color_pos[i].size())
                        step = n - color_pos[i][j - 1];
                    if (j == 1)
                        step = color_pos[i][j] - 1;
                    // cout << "@ " << m << ' ' << i << ' ' << step << endl;
                    if (step > m) {
                        if (!canPaint) {
                            cur_ok = false;
                            break;
                        }
                        int max_step = step / 2;
                        canPaint = false;
                        if (max_step > m) {
                            cur_ok = false;
                            break;
                        }
                    }
                }
                if (cur_ok) {
                    iok = true;
                    break;
                }
            }
            if (iok)
                r = m;
            else
                l = m + 1;
        }
        cout << r << endl;
    }

    return 0;
}
