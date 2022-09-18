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

    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        int turn = 0;
        turn += (n > 1);
        turn += (m > 1);
        if (n > 1)
            turn += (n % 2);
        if (m > 1)
            turn += (m % 2);
        if (turn % 2 == 0)
            cout << "Tonya";
        else
            cout << "Burenka";
        cout << endl;
    }

    return 0;
}
