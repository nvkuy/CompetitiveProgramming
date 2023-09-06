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

    int t;
    cin >> t;
    while (t--) {
        int n, m, one_cnt = 0;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m)), ans;
        vector<set<int>> c(m);
        vector<int> cnt(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
                cnt[i] += a[i][j];
            }
            one_cnt += cnt[i];
        }
        if (one_cnt % n > 0) {
            cout << -1 << endl;
            continue;
        }
        one_cnt /= n;
        for (int i = 0; i < n; i++) {
            if (cnt[i] <= one_cnt) continue;
            for (int j = 0; j < m; j++)
                if (a[i][j]) c[j].insert(i);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (cnt[i] >= one_cnt) break;
                while (true) {
                    if (a[i][j] || c[j].size() == 0) break;
                    int k = *c[j].begin();
                    c[j].erase(k);
                    if (cnt[k] == one_cnt) continue;
                    cnt[k]--, cnt[i]++;
                    ans.push_back({i + 1, k + 1, j + 1});
                    a[i][j] = 1;
                }
            }
            assert(cnt[i] >= one_cnt);
        }
        cout << ans.size() << endl;
        for (auto aa : ans) cout << aa[0] << ' ' << aa[1] << ' ' << aa[2] << endl;
    }

    return 0;
}
