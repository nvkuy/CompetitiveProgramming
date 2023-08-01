#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n), l(n), r(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    stack<int> large_pre;
    for (int i = 0; i < n; i++) {
        while (!large_pre.empty() && a[large_pre.top()] >= a[i])
            large_pre.pop();
        if (large_pre.empty())
            l[i] = 0;
        else
            l[i] = large_pre.top() + 1;
        large_pre.push(i);
    }
    while (!large_pre.empty()) large_pre.pop();
    for (int i = n - 1; i >= 0; i--) {
        while (!large_pre.empty() && a[large_pre.top()] >= a[i])
            large_pre.pop();
        if (large_pre.empty())
            r[i] = n - 1;
        else
            r[i] = large_pre.top() - 1;
        large_pre.push(i);
    }

    long long ans = -1, ans_l, ans_r;
    for (int i = 0; i < n; i++) {
        long long tans = 1LL * a[i] * (r[i] - l[i] + 1);
        if (tans > ans) {
            ans = tans;
            ans_l = l[i], ans_r = r[i];
        }
    }
    cout << ans_l + 1 << ' ' << ans_r + 1 << ' ' << ans << endl;

    return 0;
}
