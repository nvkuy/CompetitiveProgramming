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

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
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
        vector<int> a(n);
        int g = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            g = gcd(g, a[i]);
        }
        if (g == 1) {
            cout << 0 << endl;
            continue;
        }
        int cost = n;
        for (int i = 0; i < n; i++) {
            int tmp = gcd(a[i], i + 1);
            a[i] = tmp;
            if (gcd(g, tmp) != 1)
                continue;
            cost = min(cost, n - i);
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j > i; j--) {
                if (gcd(gcd(a[i], a[j]), g) == 1)
                    cost = min(cost, 2 * n - i - j);
            }
        }
        cout << cost << endl;
    }

    return 0;
}
