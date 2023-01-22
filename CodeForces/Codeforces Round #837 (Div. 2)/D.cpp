#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

//2^max_h >= n
const int max_h = 12;
vector<vector<int>> c, f;
vector<vector<int>> up;
vector<int> depth;
string s;

void buildBL(int u, int par) {
    up[u][0] = par;
    for (int i = 1; i < max_h; i++)
        up[u][i] = up[up[u][i - 1]][i - 1];
    for (int v : c[u]) {
        if (v == par)
            continue;
        depth[v] = depth[u] + 1;
        buildBL(v, u);
    }
}

int upByK(int u, int k) {
    bitset<max_h> bs(k);
    for (int i = 0; i < max_h; i++) {
        if (bs[i])
            u = up[u][i];
    }
    return u;
}

int getLCA(int u, int v) {
    if (depth[u] < depth[v])
        swap(u, v);
    int depth_diff = depth[u] - depth[v];
    u = upByK(u, depth_diff);
    for (int i = max_h - 1; i >= 0; i--) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    if (u != v)
        u = up[u][0];
    return u;
}

int dp(int u, int v) {
    if (u == v)
        return 1;
    if (upByK(u, 1) == v || upByK(v, 1) == u)
        return max(1, (s[u - 1] == s[v - 1]) * 2);
    if (f[u][v] != 0)
        return f[u][v];
    if (depth[u] > depth[v]) swap(u, v);
    int lca = getLCA(u, v);
    int nu, nv = upByK(v, 1);
    if (lca == u)
        nu = upByK(v, depth[v] - depth[u] - 1);
    else
        nu = upByK(u, 1);
    int res = 0;
    res = max(res, dp(nu, nv) + (s[u - 1] == s[v - 1]) * 2);
    res = max(res, dp(nu, v));
    res = max(res, dp(u, nv));
    f[u][v] = f[v][u] = res;
    return f[u][v];
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n, u, v;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> s;
        c.clear();
        f.clear();
        f.assign(n + 1, vector<int>(n + 1, 0));
        c.resize(n + 1);
        up.assign(n + 1, vector<int>(max_h));
        depth.assign(n + 1, 0);
        for (int i = 1; i < n; i++) {
            cin >> u >> v;
            c[u].push_back(v);
            c[v].push_back(u);
        }
        buildBL(1, 0);
        vector<int> end_point;
        for (int i = 1; i <= n; i++)
            if (c[i].size() == 1) end_point.push_back(i);
        int ans = 1;
        for (int i = 0; i < end_point.size(); i++) {
            for (int j = i + 1; j < end_point.size(); j++) {
                ans = max(ans, dp(end_point[i], end_point[j]));
            }
        }
        cout << ans << endl;
    }

    return 0;
}
