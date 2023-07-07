#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

inline void debugLocal() {
    if (!fopen("milkvisits.in", "r"))
        return;
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);
}

vector<vector<int>> c;
vector<int> cc;
string cow_type;
int cc_num = 0;

void dfs(int u, int par) {
    cc[u] = cc_num;
    for (int v : c[u]) {
        if (v != par && cow_type[u] == cow_type[v])
            dfs(v, u);
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int n, m;
    cin >> n >> m;
    c.resize(n);
    cc.assign(n, cc_num);
    cin >> cow_type;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        c[u].push_back(v);
        c[v].push_back(u);
    }
    
    for (int i = 0; i < n; i++) {
        if (cc[i] == 0) {
            cc_num++;
            dfs(i, 0);
        }
    }

    string ans;
    while (m--) {
        int u, v;
        char cow;
        cin >> u >> v >> cow;
        u--, v--;
        if (cc[u] != cc[v])
            ans.push_back('1');
        else
            ans.push_back(cow_type[u] == cow ? '1' : '0');
    }
    
    cout << ans << endl;

    return 0;
} 
