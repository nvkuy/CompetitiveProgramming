#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int, int>>> c;
vector<int> ans;
vector<bool> dd;

void dfs(int u, bool w) {
    for (int i = 0; i < c[u].size(); i++) {
        pair<int, int> p = c[u][i];
        if (!dd[p.first]) {
            dd[p.first] = true;
            ans[p.second] = (w ? 2 : 3);
            dfs(p.first, !w);
        }
    }
}

int main()
{
    int n, t, u, v;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        bool iok = true;
        ans.clear();
        ans.resize(n);
        fill(ans.begin(), ans.end(), 0);
        c.clear();
        c.resize(n + 1);
        dd.assign(n + 1, false);
        for (int i = 1; i < n; i++) {
            scanf("%d %d", &u, &v);
            c[u].push_back(make_pair(v, i));
            c[v].push_back(make_pair(u, i));
            if (c[u].size() > 2 || c[v].size() > 2)
                iok = false;
        }
        if (!iok) {
            printf("-1\n");
            continue;
        }
        u = 0;
        for (int i = 1; i < n; i++) {
            if (c[i].size() == 1) {
                u = i;
                break;
            }
        }
        ans[c[u][0].second] = 2;
        dd[u] = true;
        dfs(u, false);
        for (int i = 1; i < n; i++)
            printf("%d ", ans[i]);
        printf("\n");
    }

    return 0;
}
