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

    int t, n, ai;
    cin >> t;
    while (t--) {
        cin >> n;
        set<int> avai, exs;
        vector<int> a(n / 2);
        bool iok = true;
        for (int i = 0; i < n / 2; i++) {
            cin >> a[i];
            if (exs.find(a[i]) == exs.end())
                exs.insert(a[i]);
            else
                iok = false;
        }
        for (int i = 1; i <= n; i++) {
            if (!iok)
                break;
            if (exs.find(i) == exs.end())
                avai.insert(i);
        }
        vector<int> ans(n / 2);
        for (int i = (n / 2) - 1; i >= 0; i--) {
            if (!iok)
                break;
            auto it = avai.lower_bound(a[i]);
            if (it == avai.begin() || avai.size() == 0)
                iok = false;
            else {
                it--;
                ans[i] = *it;
                avai.erase(it);
            }
        }
        if (!iok) {
            cout << -1 << endl;
            continue;
        }
        for (int i = 0; i < n / 2; i++)
            cout << ans[i] << ' ' << a[i] << ' ';
        cout << endl;
    }

    return 0;
}
