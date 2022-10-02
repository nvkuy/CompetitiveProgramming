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

vector<vector<int>> c(101);
map<int, int> cnt;
vector<int> dd(101, 0);

void dfs(int u, int cl) {
    dd[u] = cl;
    cnt[cl]++;
    for (int v : c[u])
        if (dd[v] == 0)
            dfs(v, cl);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int n, u, v;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> u >> v;
        c[u].push_back(v);
        c[v].push_back(u);
    }
    int cl = 1;
    for (int i = 1; i <= 100; i++) {
        if (dd[i] == 0) {
            dfs(i, cl);
            cl++;
        }
    }
    int ans = 0;
    for (auto p : cnt)
        ans = max(ans, p.second);
    cout << ans << endl;

    return 0;
}
