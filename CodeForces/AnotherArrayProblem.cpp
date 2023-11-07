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
        long long n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        if (n == 2) {
            cout << max(accumulate(a.begin(), a.end(), 0LL), abs(a[1] - a[0]) * 2LL) << endl;
            continue;
        }
        if (n == 3) {
            long long ans = accumulate(a.begin(), a.end(), 0LL);
            ans = max(ans, abs(a[2] - a[0]) * 3LL);
            ans = max(ans, abs(a[0] - a[1]) * 3LL);
            ans = max(ans, abs(a[1] - a[2]) * 3LL);
            ans = max(ans, a[0] * 3LL);
            ans = max(ans, a[2] * 3LL);
            ans = max(ans, abs(a[1] - a[0]) * 2LL + a[2]);
            ans = max(ans, abs(a[2] - a[1]) * 2LL + a[0]);
            cout << ans << endl;
            continue;
        }
        long long max_val = *max_element(a.begin(), a.end());
        cout << max_val * n << endl;
    }

    return 0;
}
