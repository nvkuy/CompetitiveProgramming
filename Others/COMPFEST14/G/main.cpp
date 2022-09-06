#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

long long cnt(long long val) {
    long long res = 0;
    if (val > 1)
        res += (((val - 2) / 2) + (val % 2));
    if (val > 3)
        res += ((val - 4) / 4);
    return res;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    long long l = 0, r = 1e18, m;
    while (l < r) {
        m = (l + r) / 2;
        if (cnt(m) < n)
            l = m + 1;
        else
            r = m;
    }
    cout << r;

    return 0;
}
