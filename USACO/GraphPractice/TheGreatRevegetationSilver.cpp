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

vector<vector<pair<int, int>>> c;
vector<int> color;
bool iok = true;

void dfs(int u, int co) {
    color[u] = co;
    for (auto v : c[u]) {
        int tc = (co + v.second) % 2;
        if (color[v.first] == -1)
            dfs(v.first, tc);
        else
            iok &= (tc == color[v.first]);
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int n, m;
    cin >> n >> m;
    c.resize(n + 1);
    color.assign(n + 1, -1);
    while (m--) {
        string s;
        int u, v;
        cin >> s >> u >> v;
        c[u].push_back({v, s == "D"});
        c[v].push_back({u, s == "D"});
    }

    string ans = "1";
    for (int i = 1; i <= n; i++) {
        if (!iok) break;
        if (color[i] == -1) {
            dfs(i, 0);
            ans.push_back('0');
        }
    }
    if (!iok) ans = "0";

    cout << ans << endl;

    return 0;
}
