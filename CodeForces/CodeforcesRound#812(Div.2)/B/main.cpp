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
        int maxPos = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] > a[maxPos])
                maxPos = i;
        }
        bool iok = true;
        for (int i = 0; i < maxPos; i++)
            iok &= (a[i] <= a[i + 1]);
        for (int i = maxPos + 1; i < n; i++)
            iok &= (a[i - 1] >= a[i]);
        cout << (iok ? "YES" : "NO") << endl;
    }

    return 0;
}
