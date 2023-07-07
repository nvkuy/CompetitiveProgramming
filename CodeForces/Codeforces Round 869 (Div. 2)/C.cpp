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

    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1), b(n + 1, 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    b[0] = 0;
    for (int i = 1; i <= n; i++) {
        if (i > 2 && a[i - 2] >= a[i - 1] && a[i - 1] >= a[i])
            b[i] = 0;
        b[i] += b[i - 1];
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        if (l == r) {
            cout << 1 << endl;
            continue;
        }
        int ans = b[r] - b[l - 1];
        if (b[l] == b[l - 1]) ans++;
        if (b[l + 1] == b[l]) ans++;
        cout << ans << endl;
    }

    return 0;
}
