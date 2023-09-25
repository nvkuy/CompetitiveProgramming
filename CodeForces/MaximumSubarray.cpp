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
        long long n, k, x;
        cin >> n >> k >> x;
        vector<long long> a(n + 1), ps(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            a[i] -= x;
            ps[i] = ps[i - 1] + a[i];
        }
        long long ans = 0;
        multiset<long long> pss = { 0 };
        if (x < 0) {
            for (long long i = 1; i <= n; i++) {
                pss.insert(ps[i]);
                long long rm = max(k - (n - i), 0LL);
                for (long long j = 0; j <= k; j++) {
                    if (j > i) break;
                    assert(pss.size() > 0);
                    assert(max(rm - j, 0LL) <= i - j);
                    long long s = max(rm - j, 0LL) * x * 2LL;
                    s += ps[i] - *pss.begin();
                    ans = max(ans, s);
                    pss.erase(pss.lower_bound(ps[j]));
                }
                for (long long j = 0; j <= k; j++) {
                    if (j > i) break;
                    pss.insert(ps[j]);
                }
                assert(pss.size() == i + 1);
            }
        } else {
            for (long long i = 1; i <= n; i++) {
                pss.insert(ps[i]);
                for (long long j = 0; j <= k; j++) {
                    if (i - j < 0) break;
                    assert(pss.size() > 0);
                    long long s = j * x * 2LL;
                    s += ps[i] - *pss.begin();
                    ans = max(ans, s);
                    pss.erase(pss.lower_bound(ps[i - j]));
                }
                for (long long j = 0; j <= k; j++) {
                    if (i - j < 0) break;
                    pss.insert(ps[i - j]);
                }
                assert(pss.size() == i + 1);
            }
        }
        cout << ans << endl;
    }

    return 0;
}
