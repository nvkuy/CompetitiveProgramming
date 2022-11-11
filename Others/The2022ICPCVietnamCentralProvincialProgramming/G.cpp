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

    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<int> a(n + 1, 0);
        vector<long long> ps(n + 1, 0);
        vector<pair<long long, long long>> f(n + 1, {0, 0});
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            ps[i] = ps[i - 1] + a[i];
        }
        for (int i = k; i <= n; i++) {
            f[i].first = max(f[i - 1].first, f[i - k].second + ps[i] - ps[i - k]);
            f[i].second = max(f[i - 1].second, f[i - k].first - ps[i] + ps[i - k]);
        }
        cout << max(f[n].first, f[n].second) << endl;
    }

    return 0;
}
