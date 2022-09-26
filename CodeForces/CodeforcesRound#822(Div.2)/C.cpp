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
    string s;
    cin >> t;
    while (t--) {
        cin >> n;
        cin.ignore();
        getline(cin, s);
        vector<int> dd(n + 1, 0);
        long long cost = 0;
        for (int i = 1; i <= n; i++) {
            if (s[i - 1] == '1') {
                for (int j = 1; j * j <= i; j++) {
                    if (i % j == 0) {
                        dd[j] = 1;
                        dd[i / j] = 1;
                    }
                }
                continue;
            }
            int minCost = 1e9;
            for (int j = 1; j * j <= i; j++) {
                if (i % j == 0) {
                    if (dd[j] == 0) {
                        minCost = j;
                        break;
                    }
                    if (dd[i / j] == 0)
                        minCost = min(minCost, i / j);
                }
            }
            cost += minCost;
        }
        cout << cost << endl;
    }

    return 0;
}