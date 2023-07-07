#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long n, x, ans = 0;
    cin >> n >> x;
    vector<long long> a(n + 1), f(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (i > 1)
            f[i] = f[i - 1] + abs(a[i] - a[i - 1]);
    }
    for (long long i = 1; i <= n; i++) {
        if (f[i] * (i - 1) < x) continue;
        long long l = 1, r = i, m;
        while (l < r) {
            m = (l + r + 1) / 2;
            if ((f[i] - f[m]) * (i - m) >= x)
                l = m;
            else
                r = m - 1;
        }
        // cout << i << ' ' << l << endl;
        ans += l;
    }
    cout << ans << endl;

    return 0;
}
