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

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1), f(n + 1, 0);
        for (int i = 1; i <= n; i++) cin >> a[i];
        f[0] = 1;
        for (int i = 1; i <= n; i++) {
            if (i - a[i] > 0)
                f[i] = max(f[i], f[i - a[i] - 1]);
            if (i + a[i] <= n)
                f[i + a[i]] = max(f[i + a[i]], f[i - 1]);
        }
        cout << (f[n] ? "YES" : "NO") << endl;
    }

    return 0;
}
