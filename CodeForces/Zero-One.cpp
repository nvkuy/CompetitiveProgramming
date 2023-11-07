#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'
#define bit_cnt(x) __builtin_popcountll(x)
#define low_bit(x) __builtin_ctzll(x)

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        long long n, x, y;
        string a, b;
        cin >> n >> x >> y >> a >> b;
        a = "0" + a, b = "0" + b;
        int diff_pos = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] != b[i])
                diff_pos++;
        }
        if (diff_pos % 2) {
            cout << -1 << endl;
            continue;
        }
        vector<vector<vector<long long>>> f(n + 1, vector<vector<long long>>(n + 1, vector<long long>(2, 1e18)));
        f[0][0][1] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                if (a[i] == b[i]) {
                    
                } else {

                }
            }
        }
        cout << f[n][0][1] << endl;
    }

    return 0;
}
