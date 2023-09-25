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

/*
    define real-segment as the segment with MEX_SEG that can't be shink and still keep having MEX_SEG
    maybe: real-segment is not too much?? => try dp on real-segment
*/

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        int max_bit = 0;
        while ((1 << max_bit) <= n) max_bit++;
        vector<vector<int>> f(n + 1, vector<int>(1 << max_bit, 0));
        for (int i = 0; i <= n; i++) f[i][0] = 1;
        vector<vector<pair<int, int>>> seg_mex(n + 1);
        for (int i = 1; i <= n; i++) {
            vector<int> cnt(n + 2, 0);
            int mex = 0;
            for (int j = i; j <= n; j++) {
                cnt[a[j]]++;
                while (cnt[mex] > 0) mex++;
                if (cnt[a[i]] == 1 && cnt[a[j]] == 1 && max(a[i], a[j]) < mex)
                    seg_mex[j].push_back({i, mex});
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < (1 << max_bit); j++)
                f[i][j] = f[i - 1][j];
            for (auto seg : seg_mex[i]) {
                for (int j = 0; j < (1 << max_bit); j++) {
                    if ((j ^ seg.second) < (1 << max_bit))
                        f[i][j] = max(f[i][j], f[seg.first - 1][j ^ seg.second]);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < (1 << max_bit); i++)
            if (f[n][i]) ans = i;
        cout << ans << endl;
    }

    return 0;
}
