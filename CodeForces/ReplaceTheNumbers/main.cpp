#include <bits/stdc++.h>

using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

const int mn = 5e5 + 5;
int ans[mn], c[mn], rs[mn];

void dfs(int u) {
    if (ans[u] != 0)
        return;
    else {
        dfs(c[u]);
        ans[u] = ans[c[u]];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    memset(rs, 0, sizeof(rs));
    memset(ans, 0, sizeof(ans));
    memset(c, 0, sizeof(c));

    int q, x, y, n = 0, t;
    cin >> q;
    while (q--) {
        cin >> t;
        if (t == 1) {
            cin >> x;
            n++;
            if (rs[x] != 0)
                c[n] = rs[x];
            else
                rs[x] = n;
        } else {
            cin >> x >> y;
            if (x == y)
                continue;
            if (rs[x] == 0)
                continue;
            if (rs[y] != 0)
                c[rs[x]] = rs[y];
            else
                rs[y] = rs[x];
            rs[x] = 0;
        }
    }
    for (int i = 0; i < mn; i++) {
        if (rs[i] != 0)
            ans[rs[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        if (ans[i] == 0)
            dfs(i);
        cout << ans[i] << ' ';
    }

    return 0;
}
