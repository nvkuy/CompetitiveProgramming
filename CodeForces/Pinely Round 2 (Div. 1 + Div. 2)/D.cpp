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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> c(n, vector<int>(m, 0));
        vector<string> ans(n, string(m, '.'));
        vector<vector<int>> ver(n), hoz(m);
        bool iok = true;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < m; j++) {
                c[i][j] += (s[j] != '.');
                if (s[j] == 'R')
                    hoz[j].push_back(i);
                if (s[j] == 'D')
                    ver[i].push_back(j);
            }
            if (accumulate(c[i].begin(), c[i].end(), 0) % 2) iok = false;
        }
        for (int j = 0; j < m; j++) {
            int tmp = 0;
            for (int i = 0; i < n; i++)
                tmp += c[i][j];
            if (tmp % 2) iok = false;
        }
        if (!iok) {
            cout << -1 << endl;
            continue;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < ver[i].size(); j++) {
                int p = ver[i][j];
                if (j % 2) {
                    ans[i][p] = 'B';
                    ans[i - 1][p] = 'W';
                } else {
                    ans[i][p] = 'W';
                    ans[i - 1][p] = 'B';
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < hoz[i].size(); j++) {
                int p = hoz[i][j];
                if (j % 2) {
                    ans[p][i] = 'B';
                    ans[p][i - 1] = 'W';
                } else {
                    ans[p][i] = 'W';
                    ans[p][i - 1] = 'B';
                }
            }
        }
        for (auto &s : ans)
            cout << s << endl;
    }

    return 0;
}
