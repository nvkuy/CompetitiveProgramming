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
        long long n, m;
        cin >> n >> m;
        vector<long long> cnt_gcd(n + 1, 0);
        for (long long i = n; i >= 1; i--) {
            cnt_gcd[i] = (n / i) * ((n / i) - 1) / 2;
            for (long long j = 2 * i; j <= n; j += i)
                cnt_gcd[i] -= cnt_gcd[j];
        }
        long long cost = 0;
        for (long long i = n; i >= 2; i--) {
            long long have = cnt_gcd[i] / (i - 1);
            long long can_take = m / (i - 1);
            long long take = min(can_take, have);
            m -= take * (i - 1);
            cost += take * i;
        }
        assert(m >= 0);
        if (m > 0) {
            cout << -1 << endl;
            continue;
        }
        cout << cost << endl;
    }

    return 0;
}
