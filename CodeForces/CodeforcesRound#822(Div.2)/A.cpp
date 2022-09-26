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
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int ans = 2e9;
        for (int i = 0; i < n; i++) {
            multiset<int> s;
            for (int j = 0; j < n; j++) {
                s.insert(abs(a[i] - a[j]));
                if (s.size() > 3) {
                    auto it = s.end();
                    it--;
                    s.erase(it);
                }
            }
            int tans = 0;
            for (int ai : s)
                tans += ai;
            //cout << a[i] << '|' << tans << endl;
            ans = min(ans, tans);
        }
        cout << ans << endl;
    }

    return 0;
}