#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

vector<set<int>> ban;
set<int> rm;
vector<int> cc;

void dfs(int u, int cc_num) {
    int v = 0;
    cc[u] = cc_num;
    rm.erase(rm.find(u));
    while (true) {
        auto it = rm.upper_bound(v);
        if (it == rm.end()) break;
        v = *it;
        if (ban[u].find(v) != ban[u].end()) continue;
        dfs(v, cc_num);
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    ban.resize(n + 1);
    cc.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) rm.insert(i);
    while (m--) {
        int u, v;
        cin >> u >> v;
        ban[u].insert(v);
        ban[v].insert(u);
    }
    
    for (int i = 1; i <= n; i++)
        if (cc[i] == 0) dfs(i, i);
    
    map<int, int> tcnt;
    for (int i = 1; i <= n; i++) tcnt[cc[i]]++;
    vector<int> ans;
    for (auto p : tcnt) ans.push_back(p.second);
    sort(ans.begin(), ans.end());
    
    cout << ans.size() << endl;
    for (int ai : ans) cout << ai << ' ';
    cout << endl;

    return 0;
}
