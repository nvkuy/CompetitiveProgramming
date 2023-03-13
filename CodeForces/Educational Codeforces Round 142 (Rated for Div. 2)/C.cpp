#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

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
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        int ans = 0;
        if (a[0] > a[n - 1]) {
            ans++;
            swap(a[0], a[n - 1]);
        }
        int left = 0, right = 0, both = 0;
        for (int i = 1; i + 1 < n; i++) {
            if (a[i] < a[0] && a[i] > a[n - 1]) {
                both++;
                continue;
            }
            if (a[i] < a[0])
                left++;
            if (a[i] > a[n - 1])
                right++;
        }
        if (left > right) swap(left, right);
        int diff = right - left;
        int tmp = min(diff, both);
        both -= tmp;
        left += tmp;
        tmp = both / 2;
        left += tmp;
        right += (both - tmp);
        cout << ans + max(left, right) << endl;
    }

    return 0;
}
