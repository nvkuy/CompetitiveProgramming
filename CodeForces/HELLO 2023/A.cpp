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

    int t, n;
    string s;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> s;
        int ans = -1;
        for (int i = 0; i + 1 < n; i++) {
            if (s[i] == 'R' && s[i + 1] == 'L') {
                ans = 0;
                break;
            }
            if (s[i] == 'L' && s[i + 1] == 'R') {
                ans = i + 1;
                break;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
