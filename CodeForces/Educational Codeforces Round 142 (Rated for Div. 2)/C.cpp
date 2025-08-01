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
        vector<int> a(n), pos(n + 1);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            pos[a[i]] = i;
        }
        int rm = n, l = n / 2 + (n % 2), r = l + (n % 2 == 0), pre_l = l, pre_r = r;
        if (pos[l] > pos[r]) {
            cout << rm / 2 << endl;
            continue;
        }
        if (l != r)
            rm -= 2;
        l--, r++;
        while (true) {
            if (l < 1 || r > n) break;
            if (pos[l] > pos[pre_l]) break;
            if (pos[r] < pos[pre_r]) break;
            rm -= 2;
            pre_l = l, pre_r = r;
            l--, r++;
        }
        cout << rm / 2 << endl;
    }

    return 0;
}
