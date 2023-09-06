#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'
#define bit_cnt(x) __builtin_popcountll(x)

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> c(n + 1);
        c.resize(n + 1);
        while (m--) {
            int u, v;
            cin >> u >> v;
            c[u].push_back(v);
            c[v].push_back(u);
        }
        vector<pair<int, int>> ans;
        for (int u = 1; u <= n; u++) {
            if (c[u].size() < 4) continue;
            vector<int> pre(n + 1, -1), isChildRoot(n + 1, 0);
            vector<int> head, tail;
            for (int v : c[u]) isChildRoot[v] = 1;
            for (int v : c[u]) {
                if (head.size() > 0) break;
                queue<int> q;
                pre[v] = u;
                q.push(v);
                while (q.size() > 0) {
                    if (head.size() > 0) break;
                    int node = q.front(); q.pop();
                    for (int child : c[node]) {
                        if (head.size() > 0) break;
                        if (pre[child] == -1 && child != u) {
                            pre[child] = node;
                            q.push(child);
                            if (isChildRoot[child]) {
                                head.push_back(child);
                                head.push_back(v);
                            }
                        }
                    }
                }
            }
            if (head.size() < 2) continue;
            vector<int> used(n + 1, 0);
            int node = head[0];
            ans.push_back({u, node});
            while (pre[node] != -1) {
                ans.push_back({node, pre[node]});
                used[node] = used[pre[node]] = 1;
                node = pre[node];
            }
            for (int v : c[u]) {
                if (tail.size() >= 2) break;
                if (!used[v]) tail.push_back(v);
            }
            ans.push_back({u, tail[0]});
            ans.push_back({u, tail[1]});
            break;
        }
        if (ans.size() == 0) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        cout << ans.size() << endl;
        for (auto p : ans) cout << p.first << ' ' << p.second << endl;
    }

    return 0;
}
