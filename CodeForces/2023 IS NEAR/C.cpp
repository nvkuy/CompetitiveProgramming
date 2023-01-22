#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

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
        // bool iok = false;
        // for (int i = 1; i < 10000000; i++) {
        //     if (iok)
        //         break;
        //     iok = true;
        //     for (int j = 0; j < n; j++) {
        //         if (!iok)
        //             break;
        //         for (int k = j + 1; k < n; k++) {
        //             if (gcd(a[j] + i, a[k] + i) != 1) {
        //                 iok = false;
        //                 break;
        //             }
        //         }
        //     }
        // }
        // cout << (iok ? "YES" : "NO") << endl;
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                cout << a[j] - a[i] << "k + " << a[j] - a[i] - (a[j] % (a[j] - a[i])) << endl;
    }

    return 0;
}
