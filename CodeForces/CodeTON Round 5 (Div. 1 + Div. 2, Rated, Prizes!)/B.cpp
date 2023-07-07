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
        int n, x, cur = 0, ai;
        cin >> n >> x;
        vector<int> a(n), b(n), c(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        for (int i = 0; i < n; i++)
            cin >> c[i];
        for (int i = 0; i < n; i++) {
            if ((a[i] & x) != a[i]) break;
            cur |= a[i];
        }
        for (int i = 0; i < n; i++) {
            if ((b[i] & x) != b[i]) break;
            cur |= b[i];
        }
        for (int i = 0; i < n; i++) {
            if ((c[i] & x) != c[i]) break;
            cur |= c[i];
        }
        cout << (cur == x ? "Yes" : "No") << endl;
    }

    return 0;
}
