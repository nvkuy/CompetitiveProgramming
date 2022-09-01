#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

long long sse(long long n, long long pos) {
    return (pos + 1) * (n - pos - 1);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, x, y;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<vector<long long>> f(n, vector<long long>(2));
    f[0][0] = 0, f[0][1] = 1;
    for (int i = 1; i < n; i++) {
        f[i][0] = f[i - 1][1] + f[i - 1][0];
        f[i][1] = f[i - 1][1] + (a[i] != a[i - 1]) * i + 1;
    }
    long long ans = f[n - 1][0] + f[n - 1][1];
    /*
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int tans = 1;
            for (int k = i + 1; k <= j; k++)
                tans += (a[k] != a[k - 1]);
            ans += tans;
        }
    }
    */

    while (m--) {
        cin >> x >> y;
        x--;
        long long dt1 = 0, dt2 = 0;
        if (x - 1 >= 0) {
            if (a[x - 1] != a[x])
                dt1--;
            if (a[x - 1] != y)
                dt1++;
            dt1 *= sse(n, x - 1);
        }
        if (x + 1 < n) {
            if (a[x + 1] != a[x])
                dt2--;
            if (a[x + 1] != y)
                dt2++;
            dt2 *= sse(n, x);
        }
        ans += dt1;
        ans += dt2;
        a[x] = y;
        cout << ans << endl;
    }

    return 0;
}
