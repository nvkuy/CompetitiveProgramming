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
        long long n, m, ans = 0;
        cin >> n >> m;
        long long t1 = n >> low_bit(n), t2 = m >> low_bit(m);
        if (t1 % t2 > 0) {
            cout << -1 << endl;
            continue;
        }
        while (true) {
            n %= m;
            if (n == 0) break;
            while (n < m) {
                ans += n;
                n = n << 1;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
