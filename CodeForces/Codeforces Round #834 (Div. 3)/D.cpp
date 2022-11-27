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

    long long t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        int cnt2 = 0, cnt5 = 0;
        int t1 = n;
        while (t1 % 2 == 0) {
            cnt2++;
            t1 /= 2;
        }
        while (t1 % 5 == 0) {
            cnt5++;
            t1 /= 5;
        }
        long long ans = 1;
        while (abs(cnt2 - cnt5) != 0) {
            if (cnt2 < cnt5) {
                if (ans * 2LL > m)
                    break;
                cnt2++;
                ans *= 2LL;
            } else {
                if (ans * 5LL > m)
                    break;
                cnt5++;
                ans *= 5LL;
            }
        }
        while (ans * 10LL <= m)
            ans *= 10LL;
        long long tmp = m / ans;
        ans *= tmp;
        long long tans = ans * n;
        if (tans % 10 != 0)
            ans = n * m;
        else
            ans *= n;
        cout << ans << endl;
    }

    return 0;
}
