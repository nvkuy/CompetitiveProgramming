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
        vector<vector<long long>> f(n, vector<long long>(n, 1e18));
        for (int i = 0; i < n; i++)
            if (s1[i] == s2[i])
                f[i][i] = 0;
        for (int i = 0; i + 1 < n; i++) {
            if (s1[i] == s2[i] && s1[i + 1] == s2[i + 1])
                f[i][i + 1] = 0;
            if (s1[i] != s2[i] && s1[i + 1] != s2[i + 1])
                f[i][i + 1] = min(x, y * 2);
        }
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                if (s1[i] == s2[i] && s1[j] == s2[j])
                    f[i][j] = min(f[i + 1][j - 1], min(f[i + 1][j], f[i][j - 1]));
                if (s1[i] != s2[i] && s1[j] != s2[j])
                    f[i][j] = f[i + 1][j - 1] + min(y, (long long)(j - i) * x);
                if (s1[i] == s2[i] && s1[j] != s2[j])
                    f[i][j] = f[i + 1][j];
                if (s1[i] != s2[i] && s1[j] == s2[j])
                    f[i][j] = f[i][j - 1];
            }
        }
        if (f[0][n - 1] >= 1e18)
            f[0][n - 1] = -1;
        cout << f[0][n - 1] << endl;
    }

    return 0;
}