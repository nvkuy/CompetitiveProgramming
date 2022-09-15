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

    int r, c;
    cin >> r >> c;
    vector<vector<int>> cc(r, vector<int>(c, 0));
    string s;
    for (int i = 0; i < r; i++) {
        cin >> s;
        for (int j = 0; j < c; j++)
            cc[i][j] = (s[j] == '.' ? 1 : 0);
    }
    if (min(r, c) <= 2 && max(r, c) > 2) {
        int ans;
        vector<int> dd(max(r, c), 1);
        if (r < c) {
            for (int i = 0; i < r; i++) {
                for (int j = 1; j + 1 < c; j++)
                    dd[j] = min(dd[j], cc[i][j]);
            }
        } else {
            for (int j = 0; j < c; j++) {
                for (int i = 1; i + 1 < r; i++)
                    dd[i] = min(dd[i], cc[i][j]);
            }
        }
        for (int i = 1; i + 1 < dd.size(); i++)
            ans += dd[i];
        cout << ans;
        return 0;
    }
    int ans = 0;
    for (int i = 1; i + 1 < r; i++)
        for (int j = 1; j + 1 < c; j++)
            ans += cc[i][j];
    int stuckBoder = (max(r, c) > 2 ? 1 : 0);
    for (int i = 0; i < r; i++)
        stuckBoder = min(stuckBoder, min(cc[i][0], cc[i][c - 1]));
    for (int i = 0; i < c; i++)
        stuckBoder = min(stuckBoder, min(cc[0][i], cc[r - 1][i]));
    cout << ans + stuckBoder;

    return 0;
}
