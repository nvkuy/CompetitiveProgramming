#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'
#define bit_cnt(x) __builtin_popcountll(x)

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

long long k;
vector<vector<int>> c;
vector<long long> need_time, start, vis, real_start;

void dfs(int u) {
    vis[u] = 1;
    if (c[u].size() == 0)
        real_start[u] = start[u];
    for (int v : c[u]) {
        if (!vis[v])
            dfs(v);
        need_time[u] = max(need_time[u], need_time[v]);
    }
    long long time_in_day = need_time[u] % k;
    if (time_in_day <= start[u])
        need_time[u] += (start[u] - time_in_day);
    else
        need_time[u] += ((k - time_in_day) + start[u]);
    for (int v : c[u]) {
        if (need_time[v] + k > need_time[u])
            real_start[u] = min(real_start[u], real_start[v]);
    }
}

bool cmp(const pair<long long, long long> &p1, const pair<long long, long long> &p2) {
    if (p1.first == p2.first)
        return p1.second < p2.second;
    return p1.first < p2.first;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m >> k;
        c.clear();
        c.resize(n + 1);
        need_time.assign(n + 1, 0);
        real_start.assign(n + 1, 1e18);
        start.resize(n + 1);
        vis.assign(n + 1, 0);
        for (int i = 1; i <= n; i++) cin >> start[i];
        vector<int> isRoot(n + 1, 1);
        while (m--) {
            int u, v;
            cin >> u >> v;
            c[v].push_back(u);
            isRoot[u] = 0;
        }
        vector<pair<long long, long long>> seg;
        for (int i = 1; i <= n; i++) {
            if (isRoot[i]) {
                dfs(i);
                seg.push_back({real_start[i], need_time[i]});
            }
        }
        long long ans = 2e18;
        sort(seg.begin(), seg.end(), cmp);
        multiset<long long> r_seg;
        for (auto &sg : seg) r_seg.insert(sg.second);
        long long pre_max = 0;
        for (auto &sg : seg) {
            ans = min(ans, max(*r_seg.rbegin(), pre_max) - sg.first);
            r_seg.erase(r_seg.lower_bound(sg.second));
            pre_max = max(pre_max, sg.second + k);
        }
        cout << ans << endl;
    }

    return 0;
}
