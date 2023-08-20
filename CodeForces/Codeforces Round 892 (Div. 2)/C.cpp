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
        long long n;
        cin >> n;
        vector<long long> max_pair;
        for (long long i = n; i > 0; i--) {
            max_pair.push_back(i * i);
            max_pair.push_back(i * (i - 1));
        }
        sort(max_pair.begin(), max_pair.end(), greater<long long>());
        long long ans = 0;
        for (long long max_allow : max_pair) {
            vector<int> used(n + 1, 0);
            long long tans = 0, max_num = 0;
            for (long long i = n; i > 0; i--) {
                long long max_i = min(max_allow / i, n);
                while (max_i > 0 && used[max_i]) max_i--;
                if (max_i == 0) break;
                long long tmp = i * max_i;
                tans += tmp;
                max_num = max(max_num, tmp);
                used[max_i] = 1;
            }
            tans -= max_num;
            if (accumulate(used.begin(), used.end(), 0) == n) ans = max(ans, tans);
            else break;
        }
        cout << ans << endl;
    }

    return 0;
}
