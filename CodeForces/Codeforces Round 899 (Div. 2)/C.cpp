#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'
#define bit_cnt(x) __builtin_popcountll(x)
#define low_bit(x) __builtin_ctzll(x)

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
        vector<long long> a(n + 1, 0), ps(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            ps[i] += ps[i - 1];
            if (a[i] >= 0) ps[i] += a[i];
        }
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            long long tans = 0;
            if (i % 2) tans += a[i];
            tans += ps[n] - ps[i];
            ans = max(ans, tans);
        }
        cout << ans << endl;
    }

    return 0;
}
