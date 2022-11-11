#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

inline void debugLocal() {
    if (!fopen("input.txt", "r"))
        return;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n), b(n);
        int s1 = 0, s2 = 0, dif = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            s1 += a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            s2 += b[i];
            dif += (a[i] != b[i]);
        }
        int ans = abs(s1 - s2);
        if (ans != dif)
            ans++;
        cout << ans << endl;
    }

    return 0;
}
