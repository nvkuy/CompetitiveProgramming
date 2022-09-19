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
    long long x, y;
    string s1, s2;
    cin >> t;
    while (t--) {
        cin >> n >> x >> y;
        cin.ignore();
        getline(cin, s1);
        getline(cin, s2);
        long long numDiff = 0;
        int p1 = n + 1, p2 = -1;
        for (int i = 0; i < n; i++) {
            if (s1[i] != s2[i]) {
                numDiff++;
                p1 = min(p1, i);
                p2 = max(p2, i);
            }
        }
        if (numDiff % 2 == 1) {
            cout << -1 << endl;
            continue;;
        }
        if ((numDiff > 2) || (numDiff == 2 && p2 - p1 > 1)) {
            cout << y * (numDiff / 2) << endl;
            continue;
        }
        cout << min(x, 2 * y) * (numDiff / 2) << endl;
    }

    return 0;
}