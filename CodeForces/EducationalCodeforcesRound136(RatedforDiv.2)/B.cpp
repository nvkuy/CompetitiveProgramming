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

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> d(n), ans(n);
        for (int i = 0; i < n; i++)
            cin >> d[i];
        bool iok = true;
        ans[0] = d[0];
        for (int i = 1; i < n; i++) {
            if (ans[i - 1] - d[i] >= 0 && d[i] != 0) {
                iok = false;
                break;
            }
            ans[i] = d[i] + ans[i - 1];
        }
        if (!iok) {
            cout << -1 << endl;
            continue;
        }
        for (int ai : ans)
            cout << ai << ' ';
        cout << endl;
    }

    return 0;
}
