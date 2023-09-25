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

// try make ai != bi and sum b = min
// if sum b min and still > sum a => can't construct
// if sum a > sum b min and n = 1 => can't construct
// otherwise always posible because can always add (sum a - sum b min) to some bi

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
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
            if (a[i] == 1)
                b[i] = 2;
            else
                b[i] = 1;
            sum -= b[i];
        }
        bool iok = sum >= 0;
        if (sum > 0 && n == 1)
            iok = false;
        cout << (iok ? "YES" : "NO") << endl;
    }

    return 0;
}
