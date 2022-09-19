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

    int t, x;
    cin >> t;
    while (t--) {
        vector<int> a(4, 0);
        cin >> x >> a[1] >> a[2] >> a[3];
        vector<int> dd(4, 0);
        dd[x] = 1;
        x = a[x];
        dd[x] = 1;
        x = a[x];
        dd[x] = 1;
        x = a[x];
        dd[x] = 1;
        if ((dd[1] & dd[2] & dd[3]) == 1)
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }

    return 0;
}