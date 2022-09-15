#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, k, tt;
    cin >> tt;
    while (tt--) {
        cin >> n >> k;
        int t = n / k;
        vector<long long> cnt(k, t);
        t = n % k;
        for (int i = 1; i < k; i++) {
            if (t == 0)
                break;
            cnt[i]++;
            t--;
        }
        long long ans = (cnt[0] * (cnt[0] - 1)) / 2;
        int i1 = 1, i2 = k - 1;
        while (i1 <= i2) {
            if (i1 == i2) {
                ans += (cnt[i1] * (cnt[i1] - 1)) / 2;
                i1++;
            } else {
                ans += (cnt[i1] * cnt[i2]);
                i1++, i2--;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
