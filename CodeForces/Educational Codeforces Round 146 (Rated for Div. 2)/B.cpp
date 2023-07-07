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

    int t;
    cin >> t;
    while (t--) {
        long long int a, b;
        cin >> a >> b;
        long long ans = a + b;
        for (long long i = 1; i <= 1e5; i++) {
            long long tans = (i - 1LL) + (a / i) + (b / i) + ((b % i) > 0) + ((a % i) > 0);
            ans = min(ans, tans);
            if (b >= i) {
                long long j = b / i;
                tans = (j - 1LL) + (a / j) + (b / j) + ((b % j) > 0) + ((a % j) > 0);
                ans = min(ans, tans);
            }
            if (a >= i) {
                long long j = a / i;
                tans = (j - 1LL) + (a / j) + (b / j) + ((b % j) > 0) + ((a % j) > 0);
                ans = min(ans, tans);
            }
        }
        // for (long long i = 1; i * i <= a; i++) {
        //     long long tans = (i - 1LL) + (a / i) + (b / i) + ((b % i) > 0) + ((a % i) > 0);
        //     ans = min(ans, tans);
        //     long long j = a / i;
        //     tans = (j - 1LL) + (a / j) + (b / j) + ((b % j) > 0) + ((a % j) > 0);
        //     ans = min(ans, tans);
        // }
        // for (long long i = 1; i * i <= b; i++) {
        //     long long tans = (i - 1LL) + (a / i) + (b / i) + ((b % i) > 0) + ((a % i) > 0);
        //     ans = min(ans, tans);
        //     long long j = b / i;
        //     tans = (j - 1LL) + (a / j) + (b / j) + ((b % j) > 0) + ((a % j) > 0);
        //     ans = min(ans, tans);
        // }
        cout << ans << endl;
    }

    return 0;
}
