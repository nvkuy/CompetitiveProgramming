#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int maxNum = 1e9;

int try_cal(int n, int k1, int k2, vector<int> a, vector<int> sa) {
    map<int, int> cnt;
    for (int i = 0; i < k1; i++)
        cnt[sa[i]]++;
    if (k2 > 1)
        return min(sa[k1] * 2, maxNum);
    for (int i = 0; i < n; i++) {
        if (cnt[a[i]] > 0) {
            cnt[a[i]]--;
            a[i] = maxNum;
        }
    }
    int res = 0;
    for (int i = 0; i + 1 < n; i++) {
        int cost = min(a[i], a[i + 1]);
        if (k2 > 0)
            cost = max(a[i], a[i + 1]);
        cost = min(cost, sa[k1] * 2);
        res = max(res, cost);
    }
    return res;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<int> a(n), b;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        if (n == k) {
            cout << maxNum << endl;
            continue;
        }
        b = a;
        sort(a.begin(), a.end());
        int ans = try_cal(n, k, 0, b, a);
        if (k >= 1)
            ans = max(ans, try_cal(n, k - 1, 1, b, a));
        if (k >= 2)
            ans = max(ans, try_cal(n, k - 2, 2, b, a));
        cout << ans << endl;
    }

    return 0;
}
