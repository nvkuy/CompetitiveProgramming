#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

vector<vector<int>> c;
long long ans = 0;
vector<int> node_cnt;
const int MAXN = 1e3 + 1;
bitset<MAXN> f;

void dfs(int u) {
    node_cnt[u]++;
    int child_cnt = 0;
    for (int v : c[u]) {
        dfs(v);
        node_cnt[u] += node_cnt[v];
        child_cnt += node_cnt[v];
    }
    f.reset();
    f[0] = 1;
    for (int v : c[u])
        f |= (f << node_cnt[v]);
    long long t1, t2, tans = 0;
    for (int i = 0; i * i <= child_cnt; i++) {
        if (f[i]) {
            t1 = i, t2 = child_cnt - i;
            tans = max(tans, t1 * t2);
        }
    }
    ans += tans;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    c.resize(n + 1);
    node_cnt.assign(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        int u;
        cin >> u;
        c[u].push_back(i);
    }
    f = bitset<MAXN>(0);
    dfs(1);
    cout << ans << endl;

    return 0;
}