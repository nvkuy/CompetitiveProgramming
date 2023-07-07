#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

vector<vector<int>> c;
vector<int> num, low, cc;
stack<int> com;
int cur_time = 0;

void dfs(int u) {
    com.push(u);
    num[u] = low[u] = ++cur_time;
    for (int v : c[u]) {
        if (num[v] == 0) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        } else
            low[u] = min(low[u], num[v]);
    }
    if (low[u] == num[u]) {
        cc.push_back(u);
        int v;
        do {
            v = com.top();
            com.pop();
            low[v] = num[v] = 1e9;
        } while (v != u);
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    c.resize(n);
    num.assign(n, 0);
    low.assign(n, 1e9);
    while (m--) {
        int a, b;
        cin >> a >> b;
        c[a - 1].push_back(b - 1);
    }
    for (int i = 0; i < n; i++) {
        if (num[i] == 0) {
            if (i > 0) {
                cout << "NO" << endl;
                cout << 1 << ' ' << i + 1 << endl;
                return 0;
            }
            dfs(i);
        }
    }

    if (cc.size() == 1) {
        cout << "YES" << endl;
        return 0;
    }
    cout << "NO" << endl;
    cout << cc[0] + 1 << ' ' << 1 << endl;
    
    return 0;
}
