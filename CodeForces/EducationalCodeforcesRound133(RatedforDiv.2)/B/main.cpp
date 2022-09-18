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
        cout << n << endl;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = i + 1;
            cout << a[i] << ' ';
        }
        cout << endl;
        for (int i = n - 1; i > 0; i--) {
            swap(a[0], a[i]);
            for (int j = 0; j < n; j++)
                cout << a[j] << ' ';
            cout << endl;
        }
    }

    return 0;
}
