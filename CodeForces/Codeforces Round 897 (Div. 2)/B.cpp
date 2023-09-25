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
        int n;
        cin >> n;
        string s;
        cin >> s;
        int need_one = 0;
        for (int i = 0; i < n / 2; i++) need_one += s[i] != s[n - i - 1];
        for (int i = 0; i <= n; i++) {
            if (i < need_one) {
                cout << 0;
                continue;
            }
            int rm = i - need_one, empty = n - 2 * need_one;
            if (rm > empty) {
                cout << 0;
                continue;
            }
            if (rm % 2 == 0) {
                cout << 1;
                continue;
            }
            cout << empty % 2;
        }
        cout << endl;
    }

    return 0;
}
