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

/*

    consider n, n + 1, n + 2
    3 * (n + 2) / (n + (n + 1)) = (3n + 6) / (2n + 1)
    = 1 + (n + 5) / (2n + 1)

    => 3 * (n + 2) % (n + (n + 1)) == 0 <=> (n + 5) % (2n + 1) == 0
    with n >= 5, n + 5 < 2n + 1 => 5, 6, 7.. works

*/

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
            cout << i + 5 << ' ';
        cout << endl;

    }

    return 0;
}
