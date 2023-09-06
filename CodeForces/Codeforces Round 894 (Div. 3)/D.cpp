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
        long long l = 2, r = 1.5e9;
        while (l < r) {
            long long m = (l + r + 1) / 2;
            if ((m * (m - 1)) / 2 <= n)
                l = m;
            else
                r = m - 1;
        }
        cout << l + (n - (l * (l - 1)) / 2) << endl;
    }

    return 0;
}
