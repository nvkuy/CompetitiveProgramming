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

    int n, l, r;
    cin >> n >> l >> r;
    vector<long long> a(n + 1, 0), f(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        f[i] = f[i - 1] + a[i];
    }
    long long ans = -1e18;
    pair<int, int> ar;
    int x = 0, j = -1, y = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] < l) {
            j = -1;
            x = y = i;
            continue;
        }
        if (a[i] <= r) {
            j = i;
            while (y < j) {
                if (f[y] < f[x])
                    x = y;
                y++;
            }
        }
        if (j == -1)
            continue;
        if (ans < f[i] - f[x]) {
            ans = f[i] - f[x];
            ar = {x + 1, i};
        }
    }
    cout << ans << endl;
    cout << ar.first << ' ' << ar.second << endl;

    return 0;
}
