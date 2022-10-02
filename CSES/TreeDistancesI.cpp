#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

vector<vector<int>> c;
vector<pair<int, int>> d;
vector<int> ans;

void dfs(int u, int par) {
    multiset<int> ss;
    for (int i = 0; i < c[u].size(); i++) {
        int v = c[u][i];
        if (v == par)
            continue;
        dfs(v, u);
        ss.insert(d[v].first + 1);
        if (ss.size() > 2)
            ss.erase(ss.begin());
    }
    if (ss.size() > 0) {
        d[u].first = *(ss.begin());
        ss.erase(ss.begin());
    }
    if (ss.size() > 0) {
        d[u].second = *(ss.begin());
        ss.erase(ss.begin());
    }
    if (d[u].first < d[u].second)
        swap(d[u].first, d[u].second);
}

void getAns(int u, int par, int maxlp) {
    ans[u] = max(d[u].first, maxlp);
    // cout << u << '|' << maxlp << endl;
    for (int v : c[u]) {
        if (v == par)
            continue;
        int tl = maxlp + 1;
        if (d[v].first + 1 == d[u].first)
            tl = max(tl, d[u].second + 1);
        else
            tl = max(tl, d[u].first + 1);
        getAns(v, u, tl);
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, u, v;
    cin >> n;
    c.resize(n);
    d.assign(n, {0, 0});
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        u--, v--;
        c[u].push_back(v);
        c[v].push_back(u);
    }
    dfs(0, -1);
    ans.assign(n, 0);
    getAns(0, -1, 0);

    for (int res : ans)
        cout << res << ' ';
    cout << endl;

    // for (auto p : d)
    //     cout << p.first << '|' << p.second << endl;

    return 0;
}