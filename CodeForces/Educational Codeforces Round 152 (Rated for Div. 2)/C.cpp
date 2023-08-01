#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        vector<int> sf0(n, 0), pf1(n, 0);
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') continue;
            pf1[i] = 1;
            if (i > 0)
                pf1[i] += pf1[i - 1];
        }
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '1') continue;
            sf0[i] = 1;
            if (i + 1 < n)
                sf0[i] += sf0[i + 1];
        }
        set<pair<int, int>> real_range;
        for (int i = 0; i < m; i++) {
            int l, r;
            cin >> l >> r;
            l--, r--;
            l = l + sf0[l];
            r = r - pf1[r];
            if (l < r)
                real_range.insert({l, r});
            else
                real_range.insert({0, 0});
            // cout << "@: " << l << ' ' << r << endl;
        }
        cout << real_range.size() << endl;
    }

    return 0;
}
