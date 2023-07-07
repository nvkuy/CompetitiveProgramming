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
        string s;
        cin >> s;
        int ans = 1e9 + 7;
        for (char keep = 'a'; keep <= 'z'; keep++) {
            int max_remove = 0, cur_remove = 0;
            for (int i = 0; i < s.length(); i++) {
                if (s[i] != keep) cur_remove++;
                if (s[i] == keep || i + 1 == s.length()) {
                    max_remove = max(cur_remove, max_remove);
                    cur_remove = 0;
                }
            }
            if (max_remove == 0)
                ans = 0;
            else {
                int op = 1;
                while ((1 << op) <= max_remove) op++;
                ans = min(ans, op);
            }
        }
        cout << ans << endl;
    }

    return 0;
}
