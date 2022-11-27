#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

vector<vector<int>> c, cc;
vector<int> tmp, dd, low, cut_point;
int n, tt;

void dfs(int u, int par) {
    tmp.push_back(u + 1);
    low[u] = dd[u] = ++tt;
    int children = 0;
    for (int v = 0; v < n; v++) {
        if (c[u][v] == 1) {
            if (dd[v] == 0) {
                children++;
                dfs(v, u);
                low[u] = min(low[u], low[v]);
                if (par != -1 && low[v] >= dd[u])
                    cut_point[u] = 1;
            } else
                if (v != par) low[u] = min(low[u], dd[v]);
        }
    }
    if (par == -1 && children > 1)
        cut_point[u] = 1;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    string s;
    cin >> t;
    while (t--) {
        cin >> n;
        dd.assign(n, 0);
        low.assign(n, 1e9);
        cut_point.assign(n, 0);
        c.assign(n, vector<int>(n, 0));
        cc.clear();
        for (int i = 0; i < n; i++) {
            cin >> s;
            for (int j = 0; j < n; j++) {
                c[i][j] = max(s[j] - '0', c[i][j]);
                c[j][i] = max(s[j] - '0', c[j][i]);
            }
        }
        // cout << "@" << endl;
        tt = 0;
        int ans = 1e9 + 7;
        for (int i = 0; i < n; i++) {
            if (dd[i] == 0) {
                // cout << i << ' ';
                tmp.clear();
                dfs(i, -1);
                cc.push_back(tmp);
                if (ans > tmp.size())
                    ans = tmp.size();
                // for (int j : tmp) {
                //     if (low[j - 1] == dd[j - 1] && j - 1 != i)
                //         cut_point[j - 1] = 1;
                // }
            }
        }
        // cout << endl << "@" << endl;
        if (cc.size() == 1) {
            cout << 0 << endl;
            continue;
        }
        // cout << "CCN: " << cc.size() << endl;
        // for (int i = 0; i < cc.size(); i++) {
        //     for (int j : cc[i])
        //         cout << j << ' ';
        //     cout << endl;
        // }
        int notTooBad = -1;
        for (int i = 0; i < cc.size(); i++) {
            for (int u = 0; u < cc[i].size(); u++) {
                for (int v = u + 1; v < cc[i].size(); v++) {
                    // cout << i << ": " << cc[i][u] <<  ' ' << cc[i][v] << endl;
                    if (c[cc[i][u] - 1][cc[i][v] - 1] == 0) {
                        if (cut_point[cc[i][u] - 1] == 0)
                            notTooBad = cc[i][u];
                        if (cut_point[cc[i][v] - 1] == 0)
                            notTooBad = cc[i][v];
                    }
                    if (notTooBad > 0)
                        break;
                }
                if (notTooBad > 0)
                    break;
            }
            if (notTooBad > 0)
                break;
        }
        if (notTooBad > 0) {
            cout << 1 << endl;
            cout << notTooBad << endl;
            continue;
        }

        if (ans > 2 && cc.size() > 2) {
            cout << 2 << endl;
            cout << cc[0][0] << ' ' << cc[1][0] << endl;
            continue;
        }

        cout << ans << endl;
        for (int i = 0; i < cc.size(); i++) {
            if (ans == cc[i].size()) {
                for (int j : cc[i])
                    cout << j << ' ';
                cout << endl;
                break;
            }
        }
    }

    return 0;
}
