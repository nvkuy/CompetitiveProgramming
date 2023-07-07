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

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int ans = -1;
        for (int num_one = 0; num_one <= n; num_one++) {
            int num_zero = n - num_one;
            int tans = 0;
            tans += ((num_one * (num_one - 1)) / 2);
            tans += ((num_zero * (num_zero - 1)) / 2);
            if (tans == k) {
                ans = num_one;
                break;
            }
        }
        if (ans < 0) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        for (int i = 0; i < ans; i++)
            cout << 1 << ' ';
        for (int i = 0; i < n - ans; i++)
            cout << -1 << ' ';
        cout << endl;
    }

    return 0;
}
