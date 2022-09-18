#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

long long n, k;
vector<int> a, dd, f;
vector<vector<int>> c;
bool isDoAble;

void dfs(int u, int ans) {
    dd[u] = 1;
    for (int i = 0; i < c[u].size(); i++) {
        if (isDoAble)
            return;
        int v = c[u][i];
        if (a[v] > ans)
            continue;
        if (dd[v] == 0)
            dfs(v, ans);
        f[u] = max(f[u], f[v] + 1);
        if (dd[v] == 1 || f[u] >= k - 1)
            isDoAble = true;
    }
    if (f[u] >= k - 1)
        isDoAble = true;
    dd[u] = 2;
}

bool checkAns(int ans) {
    isDoAble = false;
    fill(dd.begin(), dd.end(), 0);
    fill(f.begin(), f.end(), 0);
    for (int i = 1; i <= n; i++) {
        if (dd[i] == 0 && a[i] <= ans)
            dfs(i, ans);
        if (isDoAble)
            return true;
    }
    return false;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int m, u, v;
    cin >> n >> m >> k;
    a.resize(n + 1);
    dd.resize(n + 1);
    f.resize(n + 1);
    c.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    while (m--) {
        cin >> u >> v;
        c[u].push_back(v);
    }
    int le = 1, ri = 1e9 + 7, mi;
    while (le < ri) {
        mi = (le + ri) / 2;
        if (checkAns(mi))
            ri = mi;
        else
            le = mi + 1;
    }
    if (ri > 1e9)
        ri = -1;
    cout << ri;

    return 0;
}
