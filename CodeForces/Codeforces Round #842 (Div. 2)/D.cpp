#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

vector<vector<int>> c;
vector<int> cc;
int cc_num;

void dfs(int u) {
    cc[u] = cc_num;
    for (int v : c[u]) {
        if (cc[v] == -1)
            dfs(v);
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        c.clear();
        c.resize(n + 1);
        cc.assign(n + 1, -1);
        cc_num = 0;
        for (int i = 0; i < n; i++)
            c[i + 1].push_back(a[i]);
        for (int i = 1; i <= n; i++) {
            if (cc[i] == -1) {
                dfs(i);
                cc_num++;
            }
        }
        int ans = n - cc_num + 1;
        for (int i = 1; i < n; i++) {
            int tmp = cc_num;
            if (cc[i] == cc[i + 1])
                tmp++;
            else
                tmp--;
            ans = min(ans, n - tmp);
        }
        cout << ans << endl;
    }

    return 0;
}
