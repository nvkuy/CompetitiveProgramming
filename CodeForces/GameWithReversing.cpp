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
        string s1, s2;
        cin >> s1 >> s2;
        int ans = 1e9, diff = 0;
        for (int i = 0; i < n; i++) diff += s1[i] != s2[i];
        int rev_cnt = max(0, diff - 1);
        if (rev_cnt % 2) ans = min(ans, diff * 2);
        else ans = min(ans, max(diff * 2 - 1, 0));
        reverse(s2.begin(), s2.end());
        diff = 0;
        for (int i = 0; i < n; i++) diff += s1[i] != s2[i];
        rev_cnt = max(0, diff - 1);
        if (diff > 0) {
            if (rev_cnt % 2 == 0) ans = min(ans, diff * 2);
            else ans = min(ans, max(diff * 2 - 1, 0));
        } else ans = min(ans, 2);
        cout << ans << endl;
    }

    return 0;
}
