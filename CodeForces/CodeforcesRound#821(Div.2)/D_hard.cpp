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
        vector<int> diff;
        for (int i = 0; i < n; i++)
            if (s1[i] != s2[i])
                diff.push_back(i);
        if (diff.size() % 2 == 1) {
            cout << -1 << endl;
            continue;
        }
        vector<long long> f(diff.size() + 1, 1e18);
        f[0] = 0;
        for (int i = 1; i <= diff.size(); i++) {
            if (i % 2) {
                f[i] = f[i - 1];
                if (i - 2 > 0)
                    f[i] = min(f[i], f[i - 2] + (diff[i - 1] - diff[i - 2]) * x);
            } else {
                f[i] = f[i - 1] + y;
                if (i - 2 >= 0)
                    f[i] = min(f[i], f[i - 2] + (diff[i - 1] - diff[i - 2]) * x);
            }
        }
        cout << f[diff.size()] << endl;
    }

    return 0;
}