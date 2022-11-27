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

    int t, n, s, ai;
    cin >> t;
    while (t--) {
        cin >> n >> s;
        multiset<int> a;
        for (int i = 0; i < n; i++) {
            cin >> ai;
            a.insert(ai);
        }
        int cs = 0;
        for (int i = 1; i <= s; i++) {
            if (cs >= s)
                break;
            if (a.count(i) > 0)
                continue;
            a.insert(i);
            cs += i;
        }
        bool iok = (cs == s);
        int pre = 0;
        for (int cur : a) {
            // cout << cur << endl;
            if (cur != pre + 1)
                iok = false;
            pre = cur;
        }
        cout << (iok ? "YES" : "NO") << endl;
    }

    return 0;
}
