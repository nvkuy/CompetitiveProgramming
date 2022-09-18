#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int n;
vector<vector<int>> c;
vector<vector<pair<int, long long>>> f;
vector<int> ans;

void dfs(int u, int par) {
    f[u][1].first = 1;
    f[u][1].second = c[u].size();
    f[u][0].second = 1;
    for (int i = 0; i < c[u].size(); i++) {
        int v = c[u][i];
        if (v != par) {
            dfs(v, u);
            pair<int, long long> tmp;
            if (f[v][1].first != f[v][0].first) {
                if (f[v][1].first > f[v][0].first)
                    tmp = f[v][1];
                else
                    tmp = f[v][0];
            } else {
                if (f[v][0].second <= f[v][1].second)
                    tmp = f[v][0];
                else
                    tmp = f[v][1];
            }
            f[u][0].first += tmp.first;
            f[u][0].second += tmp.second;
            f[u][1].first += f[v][0].first;
            f[u][1].second += f[v][0].second;
        }
    }
}

void trace(int u, int par, bool isGood) {
    if (isGood)
        ans[u] = c[u].size();
    else
        ans[u] = 1;
    for (int i = 0; i < c[u].size(); i++) {
        int v = c[u][i];
        if (v != par) {
            if (isGood)
                trace(v, u, false);
            else {
                bool isChildGood = true;
                if (f[v][0].first > f[v][1].first)
                    isChildGood = false;
                if (f[v][0].first == f[v][1].first && f[v][0].second <= f[v][1].second)
                    isChildGood = false;
                trace(v, u, isChildGood);
            }
        }
    }
}

long long getSumWeight() {
    long long sw = 0;
    for (int i = 1; i <= n; i++)
        sw += ans[i];
    return sw;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int u, v;
    cin >> n;
    ans.resize(n + 1);
    c.resize(n + 1);
    f.assign(n + 1, vector<pair<int, long long>>(2, {0, 0}));
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        c[u].push_back(v);
        c[v].push_back(u);
    }
    if (n == 2) {
        cout << "2 2\n1 1";
        return 0;
    }
    dfs(1, 0);

    bool isFirstGood = true;
    if (f[1][0].first > f[1][1].first)
        isFirstGood = false;
    if (f[1][0].first == f[1][1].first && f[1][0].second <= f[1][1].second)
        isFirstGood = false;
    trace(1, 0, isFirstGood);
    cout << max(f[1][0].first, f[1][1].first) << ' ' << getSumWeight() << endl;
    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';

    return 0;
}
