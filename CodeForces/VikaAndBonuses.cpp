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

long long fx(long long a, long long b, long long c, long long x) {
    return a * x * x + b * x + c;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        long long s, k;
        cin >> s >> k;
        long long ans = s * k;
        s += (s % 10);
        k--;
        ans = max(ans, s * k);
        if (s % 10 == 0) {
            cout << ans << endl;
            continue;
        }
        vector<int> vis(10, 0);
        while (true) {
            if (vis[s % 10] || k == 0) break;
            vis[s % 10] = 1;
            long long b = 20 * k - 4 * s, a = -80, c = s * k;
            long long x1 = max(0LL, min(-b / (2LL * a), k / 4)), x2 = min(x1 + 1, k / 4);
            ans = max(ans, fx(a, b, c, x1));
            ans = max(ans, fx(a, b, c, x2));
            s += (s % 10);
            k--;
        }
        cout << ans << endl;
    }

    return 0;
}
