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
        int x, y, n;
        cin >> x >> y >> n;
        vector<int> a(n + 1);
        a[1] = x, a[n] = y;
        int cur = 1;
        for (int i = n - 1; i > 1; i--) {
            a[i] = a[i + 1] - cur;
            cur++;
        }
        bool iok = a[1] < a[2];
        iok &= (a[2] - a[1] >= cur);
        if (!iok) {
            cout << -1 << endl;
            continue;
        }
        for (int i = 1; i <= n; i++) cout << a[i] << ' ';
        cout << endl;
    }

    return 0;
}
