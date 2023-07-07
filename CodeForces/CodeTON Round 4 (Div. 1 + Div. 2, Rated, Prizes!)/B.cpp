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
        int n;
        cin >> n;
        if (n % 2 == 0) {
            cout << -1 << endl;
            continue;
        }
        vector<int> ans;
        while (n > 1) {
            int tmp = n / 2;
            if (tmp % 2 == 1) {
                n = tmp;
                ans.push_back(2);
            } else {
                n = tmp + 1;
                ans.push_back(1);
            }
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << endl;
        for (int ai : ans) cout << ai << ' ';
        cout << endl;
    }

    return 0;
}
