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
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        long long cur = a[0], op = 0, dec_next = 0;
        for (int i = 0; i < n; i++) {
            a[i] -= dec_next;
            if (cur >= a[i]) {
                op += cur - a[i];
                cur = a[i];
            } else {
                long long dec = a[i] - cur;
                op += dec;
                dec_next += dec;
            }
        }
        op += abs(cur);
        cout << op << endl;
    }

    return 0;
}
