#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

struct edge {
    int from, to, cost;
};

vector<vector<pair<int, int>>> c;
vector<int> ans, curBit;
vector<edge> edges;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, q, a, b, x;
    cin >> n >> q;
    c.resize(n);
    ans.assign(n, 0);
    curBit.resize(n);
    while (q--) {
        cin >> a >> b >> x;
        a--, b--;
        c[a].push_back({b, x});
        c[b].push_back({a, x});
        edges.push_back({a, b, x});
    }
    for (int i = 0; i < 30; i++) {
        fill(curBit.begin(), curBit.end(), 1 << i);
        for (edge e : edges) {
            if ((e.cost & (1 << i)) != 0)
                continue;
            curBit[e.from] = curBit[e.to] = 0;
        }
        for (int j = 0; j < n; j++) {
            curBit[j] = 0;
            for (pair<int, int> p : c[j]) {
                int needBit = (p.second & (1 << i));
                curBit[j] |= (needBit ^ curBit[p.first]);
            }
            ans[j] |= curBit[j];
        }
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << ' ';

    return 0;
}
