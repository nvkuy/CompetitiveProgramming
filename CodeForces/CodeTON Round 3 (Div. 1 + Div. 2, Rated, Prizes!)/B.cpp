#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

long long cost(long long cnt0, long long cnt1) {
    if (cnt0 > 0 && cnt1 > 0)
        return cnt0 * cnt1;
    if (cnt0 == 0)
        return cnt1 * cnt1;
    return cnt0 * cnt0;
}

int lc(string &s, char c, int n) {
    int ans = 0, tans = 0;
    for (int i = 0; i < n; i++) {
        if (c != s[i]) {
            tans = 0;
            continue;
        }
        tans++;
        ans = max(ans, tans);
    }
    return ans;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n;
    string s;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> s;
        long long ans = 0;
        int cnt0 = 0;
        for (int i = 0; i < n; i++) 
            cnt0 += (s[i] == '0');
        ans = max(ans, cost(cnt0, n - cnt0));
        int t1 = lc(s, '0', n), t2 = lc(s, '1', n);
        ans = max(ans, cost(t1, 0));
        ans = max(ans, cost(0, t2));
        cout << ans << endl;
    }

    return 0;
}
