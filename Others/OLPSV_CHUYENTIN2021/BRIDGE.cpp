#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

inline void debugLocal() {
    if (!fopen("input.txt", "r"))
        return;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int t, mod = 1e9 + 7;
    string s1, s2;
    cin >> t;
    while (t--) {
        cin >> s1;
        cin >> s2;
        vector<vector<int>> f(s1.length(), vector<int>(2, 0));
        f[0][0] = (s1[0] == 'X' ? 1 : 0);
        f[0][1] = (s2[0] == 'X' ? 1 : 0);
        for (int i = 1; i < s1.length(); i++) {
            if (s1[i] == 'X')
                f[i][0] = (f[i - 1][0] + f[i - 1][1]) % mod;
            if (s2[i] == 'X')
                f[i][1] = (f[i - 1][0] + f[i - 1][1]) % mod;
        }
        cout << (f[s1.length() - 1][0] + f[s1.length() - 1][1]) % mod << endl;
    }

    return 0;
}
