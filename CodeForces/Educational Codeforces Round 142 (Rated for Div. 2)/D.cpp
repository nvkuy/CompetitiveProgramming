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

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        map<string, int> f;
        vector<vector<int>> a;
        for (int i = 0; i < n; i++) {
            vector<int> t1(m);
            vector<pair<int, int>> t2;
            for (int j = 0; j < m; j++) {
                cin >> t1[j];
                t1[j]--;
                t2.push_back({t1[j], j});
            }
            sort(t2.begin(), t2.end());
            string tmp;
            for (int j = 0; j < m; j++) {
                tmp.push_back('0' + t2[j].second);
                f[tmp] = max(f[tmp], j + 1);
            }
            a.push_back(t1);
        }
        for (int i = 0; i < n; i++) {
            string tmp;
            int ans = 0;
            for (int j = 0; j < m; j++) {
                tmp.push_back('0' + a[i][j]);
                ans = max(ans, f[tmp]);
            }
            cout << ans << ' ';
        }
        cout << endl;
    }

    return 0;
}
