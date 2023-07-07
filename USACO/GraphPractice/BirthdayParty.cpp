#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

vector<vector<int>> c;
vector<int> num, low;
int cur_time, bridge_cnt;

void dfs(int u, int par) {
    num[u] = low[u] = ++cur_time;
    for (int v : c[u]) {
        if (v == par) continue;
        if (num[v] == 0) {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] >= num[v]) {
                bridge_cnt++;
                // cout << "Found bridge " << u << ' ' << v << endl;
            }
        } else
            low[u] = min(low[u], num[v]);
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    while (true) {
        int n, m;
        cin >> n >> m;
        if (max(n, m) == 0) break;
        c.clear();
        c.resize(n);
        num.assign(n, 0);
        low.assign(n, 1e9);
        while (m--) {
            int a, b;
            cin >> a >> b;
            c[a].push_back(b);
            c[b].push_back(a);
        }
        cur_time = bridge_cnt = 0;
        dfs(0, -1);
        if (cur_time < n || bridge_cnt > 0)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        // cout << "@bridge_cnt " << bridge_cnt << endl;
    }
    
    return 0;
}
