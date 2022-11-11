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

bool in_range(long long l, long long r, long long num) {
    return (num >= l & num <= r);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int t;
    long long l, r;
    cin >> t;
    while (t--) {
        cin >> l >> r;
        long long ans = 0;
        long long ll = sqrt(l), rr = sqrt(r);
        if (ll * ll < l)
            ll++;
        if (rr * rr > r)
            rr--;
        ans += (max(rr - ll, 0LL) * 3LL);
        if (in_range(l, r, (ll - 1LL) * (ll - 1LL)))
            ans++;
        if (in_range(l, r, (ll - 1LL) * ll))
            ans++;
        if (in_range(l, r, (ll - 1LL) * (ll + 1LL)))
            ans++;
        if (ll <= rr) {
            if (in_range(l, r, rr * rr))
                ans++;
            if (in_range(l, r, (rr + 1LL) * rr))
                ans++;
            if (in_range(l, r, (rr + 2LL) * rr))
                ans++;
        }
        cout << ans << endl;
    }

    return 0;
}
