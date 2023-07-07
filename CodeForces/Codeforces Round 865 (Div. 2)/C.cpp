#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

inline void debugLocal() {
    if (!fopen("input.txt", "r"))
        return;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        if (n % 2 == 1) {
            cout << "YES" << endl;
            continue;
        }
        bool iok = true;
        long long tmp = 1e18 - a[n - 1];
        a[n - 1] += tmp;
        a[n - 2] += tmp;
        for (int i = n - 2; i > 0; i--) {
            long long diff = a[i + 1] - a[i];
            a[i] += diff;
            a[i - 1] += diff;
        }
        if (a[1] < a[0])
            iok = false;
        cout << (iok ? "YES" : "NO") << endl;
    }

    return 0;
}
