#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, s;
        cin >> n >> s;
        vector<int> a(n);
        vector<pair<long long, long long>> option(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (i == 0 || i + 1 == n || a[i] < s) option[i] = {a[i], 0};
            else {
                int rm = a[i] - s;
                option[i] = {s, rm};
                if (option[i].first < option[i].second)
                    swap(option[i].first, option[i].second);
            }
        }
        vector<vector<long long>> f(n, vector<long long>(2, 1e18));
        f[0][0] = 0;
        for (int i = 1; i + 1 < n; i++) {
            f[i][0] = min(f[i - 1][0] + option[i].second * option[i - 1].first, f[i - 1][1] + option[i].second * option[i - 1].second);
            f[i][1] = min(f[i - 1][0] + option[i].first * option[i - 1].first, f[i - 1][1] + option[i].first * option[i - 1].second);
        }
        cout << min(f[n - 2][0] + option[n - 2].first * option[n - 1].first, f[n - 2][1] + option[n - 2].second * option[n - 1].first) << endl;
    }

    return 0;
}
