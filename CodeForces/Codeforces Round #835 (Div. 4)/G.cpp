#include <bits/stdc++.h>
using namespace std;

struct edge {
    int to, weight;
};

vector<vector<edge>> c;
// int block_x;

void dfs(int u, int par, int block, int cx, set<int> &s) {
    for (auto e : c[u]) {
        if (e.to == par)
            continue;
        if (e.to == block) {
            // block_x = cx ^ e.weight;
            continue;
        }
        s.insert(cx ^ e.weight);
        dfs(e.to, u, block, cx ^ e.weight, s);
    }
}

int main() {

    int t, n, a, b, u, v, cost;
    cin >> t;
    while (t--) {
        c.clear();
        cin >> n >> a >> b;
        c.resize(n + 1);
        for (int i = 1; i < n; i++) {
            cin >> u >> v >> cost;
            c[u].push_back({v, cost});
            c[v].push_back({u, cost});
        }
        set<int> sa, sb;
        sa.insert(0);
        // block_x = -1;
        dfs(a, 0, b, 0, sa);
        dfs(b, 0, 0, 0, sb);
        bool iok = false;
        for (int x : sa) {
            if (sb.find(x) != sb.end()) {
                iok = true;
                break;
            }
        }
        // if (sa.find(block_x) != sa.end())
        //     iok = true;
        cout << (iok ? "YES" : "NO") << endl;
    }

    return 0;
}