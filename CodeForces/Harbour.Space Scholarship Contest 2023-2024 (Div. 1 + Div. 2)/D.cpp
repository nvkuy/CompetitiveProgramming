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
        int n;
        cin >> n;
        vector<vector<int>> c(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < n; j++)
                c[i][j] = s[j] - '0';
        }
        vector<int> stack(n, 0), l(n, 0), r(n, 0);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j > 0) l[j - 1] += l[j];
                l[j] = 0;
            }
            for (int j = n - 1; j >= 0; j--) {
                if (j + 1 < n) r[j + 1] += r[j];
                r[j] = 0;
            }

            for (int j = 0; j < n; j++) {
                stack[j] += l[j] + r[j];
                if ((c[i][j] + stack[j]) % 2) {
                    ans++;
                    stack[j]++;
                    l[j]++;
                    r[j]++;
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}
