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
        vector<pair<long long, int>> a(n);
        for (int i = 0; i < n; i++) {
            int ai;
            cin >> ai;
            a[i] = {ai, i};
        }
        sort(a.begin(), a.end());
        vector<long long> ans(n, 0);
        long long cur = 1;
        ans[a[0].second]++;
        for (long long i = 1; i < n; i++) {
            cur += abs(a[i].first - a[i - 1].first) * i + 1;
            ans[a[i].second] += cur;
        }
        reverse(a.begin(), a.end());
        cur = 1;
        ans[a[0].second]++;
        for (long long i = 1; i < n; i++) {
            cur += abs(a[i].first - a[i - 1].first) * i + 1;
            ans[a[i].second] += cur;
        }
        for (int i = 0; i < n; i++) cout << ans[i] - 1 << ' ';
        cout << endl;
    }

    return 0;
}