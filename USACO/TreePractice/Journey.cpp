#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> c;
vector<pair<int, double>> f;

void dfs(int u, int par) {
    
    double p = 1.0 / (c[u].size() - 1.0);
    if (par == 0) p = 1.0 / c[u].size();
    for (int v : c[u]) {
        if (v != par) {
            f[v].first = f[u].first + 1;
            f[v].second = f[u].second * p;
            dfs(v, u);
        }
    }

}

int main() {

    int n;
    cin >> n;
    c.resize(n + 1);
    f.resize(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        c[u].push_back(v);
        c[v].push_back(u);
    }

    f[1] = {0, 1};
    dfs(1, 0);

    double ans = 0;
    for (int i = 2; i <= n; i++) {
        if (c[i].size() == 1)
            ans += f[i].second * f[i].first;
    }

    cout << setprecision(7) << fixed << ans << endl;

    return 0;
}