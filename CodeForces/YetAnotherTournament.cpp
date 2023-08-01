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

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b, ps;
        for (int i = 0; i < n; i++) cin >> a[i];
        b = a;
        sort(b.begin(), b.end());
        if (m < b[0]) {
            cout << n + 1 << endl;
            continue;
        }
        int l = 1, r = n;
        while (l < r) {
            int rank = (l + r) / 2;
            int rm = m, win_cnt = 0, last = 0;
            for (int i = 0; i < n; i++) {
                if (rm < b[i]) break;
                win_cnt++;
                rm -= b[i];
                last = i;
            }
            bool iok = false;
            if (win_cnt > n - rank)
                iok = true;
            else {
                if (win_cnt == n - rank) {
                    if (a[n - rank] <= b[last])
                        iok = true;
                    else {
                        if (a[n - rank] - b[last] <= rm)
                            iok = true;
                    }
                }
            }
            if (iok)
                r = rank;
            else
                l = rank + 1;
        }
        cout << r << endl;
    }

    return 0;
}
