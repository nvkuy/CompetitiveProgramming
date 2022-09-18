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

    int n, ai;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> ai;
        a[i] = ai;
    }
    int ans = 0;
    for (int i = 1; i < n - 1; i++) {
        if (a[i - 1] + a[i] < 0)
            continue;
        if (a[i - 1] < 0) {
            a[i - 1] += a[i];
            a[i + 1] += a[i];
            a[i] = -a[i];
            ans++;
            continue;
        }
        if (a[i] < 0) {
            a[i - 1] += a[i];
            a[i + 1] += a[i];
            a[i] = -a[i];
            ans++;
        }
    }
    bool isOk = true;
    for (int i = 0; i < n; i++)
        isOk &= (a[i] >= 0);
    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';
    cout << endl;
    if (!isOk) {
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;

    return 0;
}
