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

    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    long long ans = 0;
    for (int i = 0; i < n; i += 2) {
        long long cur_sum = 0, min_pref = 0;
        for (int j = i + 1; j < n; j++) {
            if (j % 2) {
                long long min_i = max(abs(min_pref), 1LL), min_j = 1;
                long long tmp = cur_sum + min_i;
                if (tmp < 0) min_i += abs(tmp);
                else min_j = max(min_j, tmp);
                ans += max(0LL, min(a[i] - min_i + 1, a[j] - min_j + 1));
            }
            cur_sum += a[j] * (j % 2 ? -1 : 1);
            if (cur_sum + a[i] < 0) break;
            min_pref = min(min_pref, cur_sum);
        }
    }
    cout << ans << endl;

    return 0;
}
