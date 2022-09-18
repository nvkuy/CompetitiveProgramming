#include <bits/stdc++.h>

using namespace std;

int mod = 1e9 + 7;
long long gt[100001];
bool dd[100001];
vector<vector<int>> c(100001);
int co, n, m;
void dfs(int u) {
    //cout << co << endl;
    dd[u] = true;
    co++;
    for (int i = 0; i < c[u].size(); i++)
        if (!dd[c[u][i]])
            dfs(c[u][i]);
}

int main()
{
    int u, v;
    cin >> n >> m;
    while (m--) {
        cin >> u >> v;
        c[u].push_back(v);
        c[v].push_back(u);
    }
    memset(gt, 0, sizeof(gt));
    gt[0] = 1;
    for (int i = 1; i <= 100001; i++)
        gt[i] = (gt[i - 1] * i) % mod;
    //cout << gt[100001] << endl;
    memset(dd, false, sizeof(dd));
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        if (!dd[i]) {
            co = 0;
            dfs(i);
            if (co > 2)
                ans = (ans + gt[co]) % mod;
        }
    }
    cout << ans;

    return 0;
}
