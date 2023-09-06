#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'
#define bit_cnt(x) __builtin_popcountll(x)

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        string x;
        cin >> x;
        int n = x.length();
        vector<int> can(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            if (x[i] >= '5') can[i] = 1;
            if (i + 1 < n && can[i + 1] && x[i] >= '4') can[i] = 1;
        }
        for (int i = 0; i < n; i++) {
            if (can[i]) {
                for (int j = i; j < n; j++) x[j] = '0';
                if (i == 0) x = "1" + x;
                else x[i - 1]++;
                break;
            }
        }
        cout << x << endl;
    }

    return 0;
}
