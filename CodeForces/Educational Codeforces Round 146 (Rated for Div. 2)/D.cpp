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
        long long n, k;
        cin >> n >> k;
        vector<long long> f(n), d(n);
        for (int i = 0; i < n; i++) cin >> f[i];
        for (int i = 0; i < n; i++) cin >> d[i];
        int ans = n;
        vector<pair<long long, long long>> a;
        for (int i = 0; i < n; i++)
            a.push_back({f[i] * d[i], f[i]});
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++) {
            // multiset<long long> pos;
            // for (int j = 0; j < n; j++) {
            //     long long diff = abs(a[i].first - a[j].first);
            //     long long new_pos = a[j].first;
            //     if (a[i].first > a[j].first) {
            //         new_pos += (a[j].second * (diff / a[j].second));
            //         if (abs(new_pos + a[j].second - a[i].first) < abs(new_pos - a[i].first))
            //             new_pos += a[j].second;
            //     } else {
            //         new_pos -= (a[j].second * (diff / a[j].second));
            //         if (abs(new_pos - a[j].second - a[i].first) <= abs(new_pos - a[i].first))
            //             new_pos += a[j].second;
            //     }
            //     pos.insert(new_pos);
            // }
            // if (pos.begin())
        }
        cout << ans << endl;
    }

    return 0;
}
