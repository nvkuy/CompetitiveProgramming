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
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        reverse(a.begin(), a.end());
        vector<int> pf(1 << 9, 0), f = pf;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            pf = f;
            fill(f.begin(), f.end(), 0);
            f[0] = pf[0] = 1;
            for (int j = 0; j < (1 << 9); j++) {
                if (pf[j]) {
                    int num = j ^ a[i];
                    f[num] = 1;
                    ans = max(ans, num);
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}
