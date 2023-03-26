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

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return (a / gcd(a, b)) * b;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<long long, long long>> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].first >> a[i].second;
        }
        long long ans = 1, pre_gcd = a[0].first, pre_lcm = a[0].second;
        for (int i = 1; i < n; i++) {
            long long cur_lcm = lcm(pre_lcm, a[i].second);
            long long need_cur = cur_lcm / a[i].second;
            long long need_pre = cur_lcm / pre_lcm;
            if (((a[i].first % need_cur) > 0) || ((pre_gcd % need_pre) > 0)) {
                ans++;
                pre_gcd = a[i].first;
                pre_lcm = a[i].second;
            } else {
                pre_gcd = gcd(pre_gcd / need_pre, a[i].first / need_cur);
                pre_lcm = cur_lcm;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
