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

    int t, n, a, b;
    cin >> t;
    while (t--) {
        cin >> n >> a >> b;
        if (a > b)
            swap(a, b);
        if (a != 0 || b == 0 || (n - 1) % b != 0) {
            cout << -1 << endl;
            continue;
        }
        int cur = 1;
        for (int i = 0; i < (n - 1) / b; i++) {
            for (int j = 0; j < b; j++)
                cout << cur << ' ';
            if (cur == 1)
                cur += (b + 1);
            else
                cur += b;
        }
        cout << endl;
    }

    return 0;
}