#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int query(int a, int b, int c, int d) {
    cout << "? " << a << ' ' << b << ' ' << c << ' ' << d << endl;
    cout.flush();
    int rp;
    cin >> rp;
    return rp;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    pair<int, int> ans;

    int l = 0, r = n - 1, m;
    while (l < r) {
        m = (l + r + 1) / 2;
        if (query(1, m, 1, n) != m)
            r = m - 1;
        else
            l = m;
    }
    ans.first = l + 1;
    l = 0, r = n - 1;
    while (l < r) {
        m = (l + r + 1) / 2;
        if (query(1, n, 1, m) != m)
            r = m - 1;
        else
            l = m;
    }
    ans.second = l + 1;

    cout << "? " << ans.first << ' ' << ans.second;

    return 0;
}