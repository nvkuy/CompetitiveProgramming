#include <bits/stdc++.h>

using namespace std;

int comp, comps[1000], n, k, a[1000], vis[1000];
bool c[1000][1000];

void visit(int u) {
    vis[u] = comp;
    comps[comp]++;
    for (int v = 0; v < n; v++) {
        if ((c[u][v] == true) && (vis[v] == 0)) {
            visit(v);
        }
    }
}

int solve() {
    comp = 0;
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; i++) {
        if (vis[i] == 0) {
            comp++;
            visit(i);
        }
    }
    int ans = 0;
    for (int i = 1; i <= comp; i++)
        ans = max(ans, comps[i]);

    return ans;
}

int main()
{

    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    memset(c, false, sizeof(c));
    for (int i = 0; i < (n - 1); i++) {
        for (int j = i + 1; j < n; j++) {
            if (((a[i] + a[j]) % k) != 0) {
                c[i][j] = true;
                c[j][i] = true;
            }
        }
    }

    cout << solve();

    return 0;
}
