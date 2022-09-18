#include <bits/stdc++.h>

using namespace std;

int root(int v, vector<int> &par) {
    return par[v] < 0 ? v : (par[v] = root(par[v], par));
}

void mergeTree(int x, int y, vector<int> &par) {
    if ((x = root(x, par)) == (y = root(y, par)))
        return ;
    if (par[y] < par[x]) {
        swap(x, y);
    }
    par[x] += par[y];
    par[y] = x;
}

void dfs(int u, vector<bool> &dd, vector<vector<int>> &c, int ance, vector<int> &par) {
    dd[u] = true;
    for (int i = 0; i < c[u].size(); i++) {
        if (!dd[c[u][i]]) {
            par[c[u][i]] = ance;
            par[ance]--;
            dfs(c[u][i], dd, c, ance, par);
        }
    }
}

void fcc(vector<bool> &dd, int n, vector<vector<int>> &c, vector<int> &par) {
    int u;
    for (int i = 1; i <= n; i++) {
        if (!dd[i]) {
            u = i;
            dfs(i, dd, c, u, par);
        }
    }
}

int main()
{
    int n, m1, m2, u, v;
    scanf("%d %d %d", &n, &m1, &m2);
    vector<vector<int>> c1(n + 1), c2(n + 1);
    vector<bool> dd1(n + 1, false), dd2(n + 1, false);
    vector<int> par1(n + 1, -1), par2(n + 1, -1);
    while (m1--) {
        scanf("%d %d", &u, &v);
        c1[u].push_back(v);
        c1[v].push_back(u);
    }
    while (m2--) {
        scanf("%d %d", &u, &v);
        c2[u].push_back(v);
        c2[v].push_back(u);
    }
    fcc(dd1, n, c1, par1);
    fcc(dd2, n, c2, par2);
    int h = 0;
    vector<pair<int, int>> ans;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (root(i, par1) != root(j, par1) && root(i, par2) != root(j, par2)) {
                h++;
                ans.push_back(make_pair(i, j));
                mergeTree(i, j, par1);
                mergeTree(i, j, par2);
            }
        }
    }
    printf("%d\n", h);
    for (int i = 0; i < ans.size(); i++)
        printf("%d %d\n", ans[i].first, ans[i].second);

    return 0;
}
