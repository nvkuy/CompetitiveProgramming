#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int max_h = 20;
vector<vector<int>> c;
vector<vector<int>> up;
vector<int> depth;
vector<pair<int, int>> cnt;
string s;

void buildBL(int u, int par) {
    up[u][0] = par;
    if (s[u] == 'H')
        cnt[u].first++;
    else
        cnt[u].second++;
    for (int i = 1; i < max_h; i++)
        up[u][i] = up[up[u][i - 1]][i - 1];
    for (int v : c[u]) {
        if (v == par)
            continue;
        depth[v] = depth[u] + 1;
        cnt[v].first += cnt[u].first;
        cnt[v].second += cnt[u].second;
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

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, x, y;
    cin >> n >> m;
    c.resize(n);
    depth.assign(n, 0);
    up.assign(n, vector<int>(max_h));
    cnt.assign(n, {0, 0});
    cin >> s;
    for (int i = 1; i < n; i++) {
        cin >> x >> y;
        x--, y--;
        c[x].push_back(y);
        c[y].push_back(x);
    }
    buildBL(0, 0);
    string ans;
    while (m--) {
        char ci;
        cin >> x >> y >> ci;
        x--, y--;
        int lca = getLCA(x, y);
        pair<int, int> tmp = {0, 0};
        tmp.first -= (2 * cnt[lca].first);
        tmp.second -= (2 * cnt[lca].second);
        tmp.first += (cnt[x].first + cnt[y].first);
        tmp.second += (cnt[x].second + cnt[y].second);
        if (s[lca] == 'H')
            tmp.first++;
        else
            tmp.second++;
        bool isOk;
        if (ci == 'H')
            isOk = (tmp.first > 0);
        else
            isOk = (tmp.second > 0);
        ans.push_back(char(isOk + '0'));
    }
    cout << ans;

    return 0;
}