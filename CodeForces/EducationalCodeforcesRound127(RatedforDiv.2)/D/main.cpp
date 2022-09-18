#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, x, n;
    cin >> t;
    while (t--) {
        cin >> n >> x;
        vector<int> a(n);
        int amax = 0, amin = 1e9;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            amax = max(amax, a[i]);
            amin = min(amin, a[i]);
        }
        int l1 = 1, r1 = max(1, amin - 1), l2 = min(amax + 1, x), r2 = x;
        long long initCost = 0, cost1 = 2e18, cost2 = ((amax >= x) ? 0LL : 2e18), tcost1, tcost2;
        for (int i = 1; i < n; i++)
            initCost += abs(a[i] - a[i - 1]);
        cost1 = min(cost1, (long long)min(min(abs(a[0] - l1), abs(a[0] - r1)), min(abs(a[n - 1] - l1), abs(a[n - 1] - r1))));
        cost2 = min(cost2, (long long)min(min(abs(a[0] - l2), abs(a[0] - r2)), min(abs(a[n - 1] - l2), abs(a[n - 1] - r2))));
        for (int i = 1; i < n; i++) {
            tcost1 = tcost2 = -abs(a[i] - a[i - 1]);
            tcost1 += min(abs(a[i - 1] - l1) + abs(a[i] - r1), abs(a[i] - l1) + abs(a[i - 1] - r1));
            tcost2 += min(abs(a[i - 1] - l2) + abs(a[i] - r2), abs(a[i] - l2) + abs(a[i - 1] - r2));
            cost1 = min(cost1, tcost1), cost2 = min(cost2, tcost2);
            //cout << i << ": " << cost1 << '|' << cost2 << endl;
        }
        cout << initCost + (r1 - l1) + (r2 - l2) + cost1 + cost2 << endl;
    }

    return 0;
}
