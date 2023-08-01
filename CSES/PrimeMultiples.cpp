#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long n, ans = 0;
    int k;
    cin >> n >> k;
    vector<long long> a(k);
    for (int i = 0; i < k; i++) cin >> a[i];

    for (int mask = 1; mask < (1 << k); mask++) {
        long long mask_lcm = 1;
        for (int i = 0; i < k; i++) {
            if (((1 << i) & mask) != 0) {
                if (mask_lcm > (n / a[i]))
                    mask_lcm = n + 1;
                else
                    mask_lcm *= a[i];
            }
            if (mask_lcm > n) break;
        }
        if (!(__builtin_popcount(mask) & 1))
            mask_lcm = -mask_lcm;
        ans += (n / mask_lcm);
    }

    cout << ans << endl;

    return 0;

}