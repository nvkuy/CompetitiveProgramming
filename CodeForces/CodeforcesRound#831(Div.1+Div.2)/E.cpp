#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

inline void debugLocal() {
    if (!fopen("input.txt", "r"))
        return;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

vector<vector<int>> c;
vector<pair<int, int>> f;

void dfs(int u) {
    if (c[u].size() == 0) {
        f[u] = {1, 1};
        return;
    }
    int sumF = 0, maxL = 0;
    for (int v : c[u]) {
        dfs(v);
        sumF += f[v].first;
        maxL = max(maxL, f[v].second);
    }
    f[u].second = maxL + 1;
    f[u].first = max(sumF, f[u].second);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    //debugLocal();

    int n, pi, ans = 0;
    cin >> n;
    c.resize(n + 1);
    f.assign(n + 1, {0, 0});
    for (int i = 2; i <= n; i++) {
        cin >> pi;
        c[pi].push_back(i);
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
        ans = max(ans, f[i].first);
    cout << ans << endl;

    return 0;
}
