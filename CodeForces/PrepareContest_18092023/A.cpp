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
        vector<long long> a(n), b(n);
        long long sum = 0;
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++) {
            sum += a[i];
            if (a[i] == 1)
                b[i] = 2;
            else
                b[i] = 1;
            sum -= b[i];
        }
        for (int i = 0; i < n; i++) {
            if (sum <= 0) break;
            if (b[i] + sum == a[i])
                sum = 1;
            else
                sum = 0;
        }
        cout << (sum == 0 ? "YES" : "NO") << endl;
    }

    return 0;
}
