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

    int t, q, n, x, y;
    cin >> t;
    while (t--) {
        cin >> n >> q;
        vector<int> a(n), f(n, 0);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int curChamp = 0;
        for (int i = 1; i < n; i++) {
            if (a[curChamp] < a[i])
                curChamp = i;
            f[curChamp]++;
        }
        /*
        for (int i = 0; i < n; i++)
            cout << f[i] << ' ';
        cout << endl;
        */
        while (q--) {
            cin >> x >> y;
            x--;
            int ans = 0;
            if (a[x] == n && y >= n)
                ans += (y - n + 1);
            if (x > 1)
                y = max(0, y - x + 1);
            //cout << x << '|' << y << '|' << f[x] << endl;
            ans += min(y, f[x]);
            cout << ans << endl;
        }
    }

    return 0;
}
