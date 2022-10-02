#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

inline void debugLocal() {
    if (!fopen("input.txt", "r"))
        return;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

struct edge {
    int to, cost;
    edge();
    edge(int u, int c): to(u), cost(c) {}
};

vector<vector<edge>> c;
vector<pair<int, int>> f;

void dfs(int u, int par, int maxH) {
    vector<int> path;
    for (edge e : c[u]) {
        if (e.to == par)
            continue;
        dfs(e.to, u, maxH);
        path.push_back(f[e.to].first + e.cost);
        f[u].second += f[e.to].second;
    }
    sort(path.begin(), path.end());
    while (true) {
        if (path.size() == 0)
            break;
        if (path.back() > maxH) {
            path.pop_back();
            f[u].second++;
            continue;
        }
        if (path.size() == 1)
            break;
        if (path[path.size() - 1] + path[path.size() - 2] > maxH) {
            path.pop_back();
            f[u].second++;
            continue;
        }
        break;
    }
    if (path.size() > 0)
        f[u].first = path.back();
}

bool check(int maxL, int numTree) {
    f.assign(c.size(), {0, 0});
    dfs(1, 0, maxL);
    // cout << "TRY " << maxL << '|' << numTree << '|' << f[1].second << endl;
    // for (int i = 1; i < c.size(); i++)
    //     cout << f[i].second << ' ';
    // cout << endl;
    return (f[1].second < numTree);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int n, m, u, v, cost;
    cin >> n >> m;
    c.resize(n + 1);
    for (int i = 1; i < n; i++) {
        cin >> u >> v >> cost;
        c[u].push_back({v, cost});
        c[v].push_back({u, cost});
    }
    int l = 0, r = 1e9, mm;
    while (l < r) {
        mm = (l + r) / 2;
        if (check(mm, m))
            r = mm;
        else
            l = mm + 1;
    }
    cout << r << endl;

    return 0;
}
