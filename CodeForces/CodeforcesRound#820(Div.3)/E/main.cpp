#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

long long query(long long a, long long b) {
    cout << "? " << a << ' ' << b << endl;
    cout.flush();
    long long rp;
    cin >> rp;
    return rp;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long ans = -1;
    for (int i = 2; i < 27; i++) {
        long long x = query(1, i);
        long long y = query(i, 1);
        if (x + y < 0)
            ans = i - 1;
        if (x != y)
            ans = x + y;
        if (ans != -1)
            break;
    }
    cout << "! " << ans;

    return 0;
}
