#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

vector<vector<int>> c;
vector<set<int>> ans;
vector<int> dd;
int tt;

void dfs(int u) {
    dd[u] = 1;
    ans[u].insert(tt);
    tt++;
    for (int v : c[u]) {
        if (dd[v] == 0) {
            // cout << u << " -> " << v << endl;
            dfs(v);
        }
        for (int x : ans[v])
            ans[u].insert(x);
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n;
    string s;
    cin >> t;
    while (t--) {
        cin >> n;
        c.clear(); c.resize(n);
        ans.clear(); 
        ans.resize(n);
        dd.assign(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> s;
            for (int j = 0; j < n; j++) {
                if (s[j] == '1') {
                    c[j].push_back(i);
                }
            }
            // cout << "READED: " << s << endl;
        }
        tt = 1;
        for (int i = 0; i < n; i++) {
            if (dd[i] == 0)
                dfs(i);
        }
        for (int i = 0; i < n; i++) {
            cout << ans[i].size() << ' ';
            for (int j : ans[i])
                cout << j << ' ';
            cout << endl;
        }
    }

    return 0;
}
