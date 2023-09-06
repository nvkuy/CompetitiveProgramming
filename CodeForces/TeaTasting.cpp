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
        vector<long long> a(n + 2, 0), b(n + 2, 1e9 + 7), ps(n + 2, 0);
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) cin >> b[i];
        for (int i = 1; i <= n + 1; i++) ps[i] = ps[i - 1] + b[i];
        long long cur = 0;
        vector<long long> end(n + 2, 0), ans(n + 2, 0);
        for (int i = 1; i <= n; i++) {
            cur++;
            int l = i, r = n + 1, m;
            while (l < r) {
                m = (l + r) / 2;
                if (ps[m] - ps[i - 1] > a[i])
                    r = m;
                else
                    l = m + 1;
            }
            // cout << i << ' ' << r << endl;
            end[r]++;
            ans[r] += a[i] - (ps[r - 1] - ps[i - 1]);
            cur -= end[i];
            ans[i] += b[i] * cur;
        }
        for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
        cout << endl;
    }

    return 0;
}
