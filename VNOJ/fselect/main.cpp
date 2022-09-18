#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> c, meet, up;
vector<int> h;
int root, hmax = 20;

void build(int u, int par) {
    up[u][0] = par;
    for (int i = 1; i < hmax; i++)
        up[u][i] = up[up[u][i - 1]][i - 1];
    for (int v : c[u]) {
        if (v == par)
            continue;
        h[v] = h[u] + 1;
        build(v, u);
    }
}

int getLCA(int u, int v) {
    if (h[u] > h[v])
        swap(u, v);
    int dh = h[v] - h[u];
    bitset<20> bs(dh);
    for (int i = 0; i < hmax; i++) {
        if (bs[i])
            v = up[v][i];
    }
    for (int i = hmax - 1; i >= 0; i--) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    if (u != v)
        u = up[u][0];
    return u;
}

int dist(int u, int v) {
    int lca = getLCA(u, v);
    return h[u] + h[v] - 2 * h[lca];
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, k, a, b;
    cin >> n >> k;
    c.resize(n + 1);
    meet.resize(k + 1);
    up.assign(n + 1, vector<int>(hmax));
    h.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a >> b;
        meet[a].push_back(i);
        if (b == 0)
            root = i;
        else {
            c[i].push_back(b);
            c[b].push_back(i);
        }
    }
    build(root, root);
    for (int i = 1; i <= k; i++) {
        vector<pair<int, int>> sh;
        for (int v : meet[i])
            sh.push_back(make_pair(h[v], v));
        sort(sh.begin(), sh.end(), greater<pair<int, int>>());
        int ans = 0;
        for (int j = 0; j < sh.size(); j++)
            ans = max(ans, dist(sh[j].second, sh[0].second));
        cout << ans << '\n';
    }

    return 0;
}
