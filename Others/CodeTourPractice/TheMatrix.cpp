#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

vector<vector<int>> g;
vector<int> mt;
vector<bool> used;

bool try_kuhn(int v) {
    if (used[v])
        return false;
    used[v] = true;
    for (int to : g[v]) {
        if (mt[to] == -1 || try_kuhn(mt[to])) {
            mt[to] = v;
            return true;
        }
    }
    return false;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> a[i][j];

        long long sum_line = accumulate(a[0].begin(), a[0].end(), 0);
        bool iok = true;
        for (int i = 0; i < n; i++) {
            long long s1 = 0, s2 = 0;
            for (int j = 0; j < n; j++) {
                s1 += a[i][j];
                s2 += a[j][i];
            }
            if (s1 != sum_line || s2 != sum_line) {
                iok = false;
                break;
            }
        }

        if (!iok) {
            cout << -1 << endl;
            continue;
        }

        vector<pair<int, vector<int>>> ans;
        while (true) {

            if (accumulate(a[0].begin(), a[0].end(), 0) == 0) break;

            vector<int> pos(n);
            g.clear();
            mt.assign(2 * n, -1);
            g.resize(2 * n);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (a[i][j] > 0) {
                        g[i].push_back(j + n);
                        g[j + n].push_back(i);
                    }
                }
            }
            for (int v = 0; v < 2 * n; ++v) {
                used.assign(2 * n, false);
                try_kuhn(v);
            }

            for (int i = 0; i < n; i++) {
                assert(mt[i] != -1);
                pos[i] = mt[i] - n;
            }

            int dt = 1e9;
            for (int i = 0; i < n; i++)
                dt = min(a[i][pos[i]], dt);
            ans.push_back({dt, pos});
            for (int i = 0; i < n; i++)
                a[i][pos[i]] -= dt;

        }

        cout << ans.size() << endl;
        for (auto tmp : ans) {
            cout << tmp.first << ' ';
            for (auto p : tmp.second) cout << p + 1 << ' ';
            cout << endl;
        }

    }

    return 0;
}
