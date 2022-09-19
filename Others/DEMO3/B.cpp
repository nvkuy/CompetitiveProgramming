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

    vector<int> a(6), b(6);
    b = {1, 5, 10, 50, 100, 500};
    for (int i = 0; i < 6; i++)
        cin >> a[i];
    int x, ans = 0;
    cin >> x;
    for (int i = 5; i >= 0; i--) {
        if (x == 0)
            break;
        int tmp = min(x / b[i], a[i]);
        x -= (b[i] * tmp);
        ans += tmp;
    }
    if (x > 0) {
        cout << -1;
        return 0;
    }
    cout << ans;

    return 0;
}