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

/*
    idea:
    1. can easy to caculate when ai = aj
    2. lim bi + bj <= 2 * n => min(ai, aj) <= sqrt(2 * n)
    let ai > aj => two case:
    case 1: max(ai, aj) <= sqrt(2 * n)
    case 2: aj <= sqrt(2 * n)
    => can bruteforce on aj => for each {ai, bi}, try all aj => all bj => ans
*/

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        vector<long long> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        long long lim = sqrt(2 * n), ans = 0;
        vector<vector<int>> cnt(lim + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < n; i++)
            if (a[i] <= lim) cnt[a[i]][b[i]]++;
        map<pair<long long, long long>, int> cnt_pre;
        for (int i = 0; i < n; i++) {
            long long bj = a[i] * a[i] - b[i];
            if (cnt_pre.find({a[i], bj}) != cnt_pre.end())
                ans += cnt_pre[{a[i], bj}];
            cnt_pre[{a[i], b[i]}]++;
        }
        for (int i = 0; i < n; i++) {
            for (long long aj = 1; aj <= min(a[i] - 1, lim); aj++) {
                long long bj = a[i] * aj - b[i];
                if (bj <= n && bj > 0) ans += cnt[aj][bj];
            }
        }
        cout << ans << endl;
    }

    return 0;
}
