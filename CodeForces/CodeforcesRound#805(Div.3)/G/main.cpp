#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int max_h = 20;
vector<vector<int>> c;
vector<vector<int>> up;
vector<int> depth;

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

int getLCA(int u, int v) {
    if (depth[u] < depth[v])
        swap(u, v);
    int depth_diff = depth[u] - depth[v];
    bitset<max_h> bs(depth_diff);
    for (int i = 0; i < max_h; i++) {
        if (bs[i])
            u = up[u][i];
    }
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

bool isParentOfV(int u, int v) {
    int tmp = getLCA(u, v);
    return tmp == u;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, q, a, b, k;
    cin >> n;
    c.resize(n + 1);
    depth.resize(n + 1);
    up.assign(n + 1, vector<int>(max_h));
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        c[a].push_back(b);
        c[b].push_back(a);
    }
    depth[1] = 0;
    buildBL(1, 1);
    cin >> q;
    while (q--) {
        cin >> k;
        vector<int> picked(k, 0);
        vector<pair<int, int>> sh;
        for (int i = 0; i < k; i++) {
            cin >> a;
            sh.push_back({depth[a], a});
        }
        bool iok = true;
        sort(sh.begin(), sh.end(), greater<pair<int, int>>());
        int j = 0; picked[j] = 1;
        for (int i = 1; i < k; i++) {
            a = sh[j].second;
            b = sh[i].second;
            if (!isParentOfV(b, a))
                continue;
            if (picked[i] == 0) {
                picked[i] = 1;
                j = i;
            }
        }
        b = sh[j].second;
        j = k - 1;
        for (int i = 0; i < k; i++) {
            if (picked[i] == 0) {
                j = i;
                break;
            }
        }
        picked[j] = 1;
        int a = getLCA(sh[j].second, sh[0].second);
        if (depth[a] > depth[b])
            iok = false;
        for (int i = j + 1; i < k; i++) {
            a = sh[j].second;
            b = sh[i].second;
            if (!isParentOfV(b, a)) {
                if (picked[i] == 0) {
                    iok = false;
                    break;
                }
                continue;
            }
            if (picked[i] == 0) {
                picked[i] = 1;
                j = i;
                continue;
            }
        }
        cout << (iok ? "YES" : "NO") << endl;
    }

    return 0;
}
