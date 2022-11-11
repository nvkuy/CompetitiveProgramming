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
    t = 1;
    while (t--) {
        cin >> n;
        vector<int> a(n);
        set<int> s;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            s.insert(a[i]);
        }
        a.clear();
        for (int ai : s)
            a.push_back(ai);
        n = a.size();
        if (n == 1)
            cout << 0 << endl;
        else if (n == 2)
            cout << (a[n - 1] - a[0]) * 2 << endl;
        else {
            int ans = a[n - 1] - a[0] + max(a[n - 1] - a[n - 2], a[1] - a[0]);
            for (int i = 0; i + 2 < n; i++) {
                ans = max(ans, a[i + 1] + a[i + 2] - 2 * a[i]);
                ans = max(ans, 2 * a[i + 2] - a[i] - a[i + 1]);
            }
            cout << ans << endl;
        }
    }

    return 0;
}
