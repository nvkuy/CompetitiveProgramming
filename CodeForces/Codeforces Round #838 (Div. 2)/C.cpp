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

    int t, n, mod = 998244353;
    vector<int> p2(2e5 + 3, 0);
    p2[0] = 1;
    for (int i = 1; i <= 2e5; i++)
        p2[i] = (p2[i - 1] * 2) % mod;
    string s;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> s;
        int ans = 0, chain = 0;
        for (int i = 0; i < s.length(); i++) {
            if (i == 0 || s[i] != s[i - 1])
                chain = 0;
            else
                chain++;
            ans = (ans + p2[chain]) % mod;
        }
        cout << ans << endl;
    }

    return 0;
}
