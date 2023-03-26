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

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int t;
    cin >> t;
    while (t--) {
        map<int, int> last_join;
        int m;
        cin >> m;
        vector<int> ans(m, -1);
        for (int i = 0; i < m; i++) {
            int n, ai;
            cin >> n;
            for (int j = 0; j < n; j++) {
                cin >> ai;
                last_join[ai] = i;
            }
        }
        for (auto p : last_join) {
            if (ans[p.second] == -1)
                ans[p.second] = p.first;
        }
        bool hasAns = true;
        for (int i = 0; i < m; i++)
            if (ans[i] < 0) hasAns = false;
        if (!hasAns) {
            cout << -1 << endl;
            continue;
        }
        for (int ai : ans) cout << ai << ' ';
        cout << endl;
    }

    return 0;
}
