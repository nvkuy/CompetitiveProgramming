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
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        bool pick1 = false, pick2 = false;
        int sb1 = -1e9 - 9, sb2 = -1e9 - 9;
        long long sum_odd = 0, sum_even = 0;
        for (int i = 0; i < n; i += 2) {
            sb1 = max(sb1, a[i]);
            if (a[i] >= 0)
                pick1 = true;
            sum_even += max(0, a[i]);
        }
        for (int i = 1; i < n; i += 2) {
            sb2 = max(sb2, a[i]);
            if (a[i] >= 0)
                pick2 = true;
            sum_odd += max(0, a[i]);
        }
        if (!pick1) sum_even = sb1;
        if (!pick2) sum_odd = sb2;
        cout << max(sum_even, sum_odd) << endl;
    }

    return 0;
}
