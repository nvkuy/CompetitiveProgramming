#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

inline void debugLocal() {
    if (!fopen("planting.in", "r"))
        return;
    freopen("planting.in", "r", stdin);
    freopen("planting.out", "w", stdout);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int n, u, v;
    cin >> n;
    vector<int> c(n + 1, 0);
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        c[u]++, c[v]++;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, c[i] + 1);
    cout << ans << endl;

    return 0;
}
