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
        int n, m, k;
        cin >> n >> m >> k;
        vector<long long> a(n), b(m);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) cin >> b[i];
        multiset<long long> s1(a.begin(), a.end());
        multiset<long long> s2(b.begin(), b.end());
        int t1 = *s1.begin(), t2 = *s2.rbegin();
        if (t1 < t2) {
            s1.erase(s1.lower_bound(t1));
            s2.erase(s2.lower_bound(t2));
            s1.insert(t2);
            s2.insert(t1);
        }
        k--;
        if (k == 0) {
            long long ans = 0;
            for (long long tt : s1) ans += tt;
            cout << ans << endl;
            continue;
        }
        t1 = *s1.rbegin(), t2 = *s2.begin();
        if (t1 > t2) {
            s1.erase(s1.lower_bound(t1));
            s2.erase(s2.lower_bound(t2));
            s1.insert(t2);
            s2.insert(t1);
        }
        k--;
        if (k == 0) {
            long long ans = 0;
            for (long long tt : s1) ans += tt;
            cout << ans << endl;
            continue;
        }
        if (k % 2) {
            t1 = *s1.begin(), t2 = *s2.rbegin();
            if (t1 < t2) {
                s1.erase(s1.lower_bound(t1));
                s2.erase(s2.lower_bound(t2));
                s1.insert(t2);
                s2.insert(t1);
            }
        }
        long long ans = 0;
        for (long long tt : s1) ans += tt;
        cout << ans << endl;
    }

    return 0;
}
