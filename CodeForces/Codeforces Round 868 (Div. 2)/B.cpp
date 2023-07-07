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
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        int bad_pos = 0;
        for (int i = 0; i < n; i++) {
            if (abs(a[i] - i - 1) % k != 0)
                bad_pos++;
        }
        // cout << "TEST: " << bad_pos << endl;
        if (bad_pos == 0) {
            cout << 0 << endl;
            continue;
        }
        if (bad_pos == 2) {
            cout << 1 << endl;
            continue;
        }
        cout << -1 << endl;
    }

    return 0;
}
