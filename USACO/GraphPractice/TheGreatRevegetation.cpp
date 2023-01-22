#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

inline void debugLocal() {
    if (!fopen("revegetate.in", "r"))
        return;
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int n, u, v, m;
    cin >> n >> m;
    vector<vector<int>> c(n + 1);
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        c[u].push_back(v);
        c[v].push_back(u);
    }
    vector<int> ans(n + 1, -1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 4; j++) {
            ans[i] = j;
            bool iok = true;
            for (int k : c[i]) {
                if (ans[k] == ans[i])
                    iok = false;
            }
            if (iok)
                break;
        }
        cout << ans[i];
    }
    cout << endl;

    return 0;
}
