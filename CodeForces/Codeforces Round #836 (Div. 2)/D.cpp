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

    long long t, n, inf = 1e9;
    cin >> t;
    while (t--) {
        cin >> n;
        long long ans1 = -1, ans2 = -1;
        for (long long diff = 0; diff * diff < inf; diff++) {
            long long sum_arr = diff * diff;
            long long avg_arr = sum_arr / n;
            long long min_num = avg_arr, max_num = min_num + (sum_arr % n);
            if (diff < max_num - min_num)
                continue;
            long long add_more = diff - (max_num - min_num);
            if (add_more % n > 0)
                continue;
            max_num += add_more;
            long long add_too_much = add_more / n;
            min_num -= add_too_much;
            max_num -= add_too_much;
            if (min_num + 2 > max_num)
                continue;
            if (min_num > max_num || min_num <= 0 || max_num > inf)
                continue;
            ans1 = min_num, ans2 = max_num;
            // cout << sum_arr << endl;
            break;
        }
        for (int i = 0; i < n - 2; i++)
            cout << ans1 + i << ' ';
        cout << ans1 + n << ' ';
        cout << ans2 << endl;
    }

    return 0;
}
