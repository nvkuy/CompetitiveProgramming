#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int root(int v, vector<int> &par) {
    return par[v] < 0 ? v : (par[v] = root(par[v], par));
}

void mergeSet(int x, int y, vector<int> &par) {
    if ((x = root(x, par)) == (y = root(y, par)))
        return ;
    if (par[y] < par[x])
        swap(x, y);
    par[x] += par[y];
    par[y] = x;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<int> par1(n + 1, -1), par2(n + 1, -1), ans(m, 0), fixed(m, -1);
        vector<pair<int, int>> edges(m);
        for (int i = 0; i < m; i++)
            cin >> edges[i].first >> edges[i].second;
        for (int i = 0; i < m; i++) {
            if (root(edges[i].first, par1) != root(edges[i].second, par1)) {
                mergeSet(edges[i].first, edges[i].second, par1);
                ans[i] = 1;
                //cout << "Try pick " << i << endl;
            }
        }
        fill(par1.begin(), par1.end(), -1);
        for (int i = 0; i < m; i++) {
            if (ans[i] == 1)
                continue;
            if (root(edges[i].first, par2) != root(edges[i].second, par2)) {
                mergeSet(edges[i].first, edges[i].second, par2);
                fixed[i] = 0;
            } else {
                mergeSet(edges[i].first, edges[i].second, par1);
                fixed[i] = 1;
            }
            //cout << "Fixed " << i << ' ' << fixed[i] << endl;
        }
        fill(ans.begin(), ans.end(), 0);
        for (int i = 0; i < m; i++) {
            if (fixed[i] != -1) {
                ans[i] = fixed[i];
                continue;
            }
            if (root(edges[i].first, par1) != root(edges[i].second, par1)) {
                mergeSet(edges[i].first, edges[i].second, par1);
                ans[i] = 1;
            }
        }
        for (int i = 0; i < m; i++)
            cout << ans[i];
        cout << endl;
    }

    return 0;
}
