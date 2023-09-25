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
        vector<long long> a(n), b(n);
        long long min_a = 1e18, min_b = 1e18;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            min_a = min(min_a, a[i]);
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            min_b = min(min_b, b[i]);
        }
        cout << min(accumulate(a.begin(), a.end(), 0LL) + n * min_b, accumulate(b.begin(), b.end(), 0LL) + n * min_a) << endl;
    }

    return 0;
}
