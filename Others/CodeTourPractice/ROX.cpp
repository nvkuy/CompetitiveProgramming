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

    int n, q, cur_xor = 0;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        int ai;
        cin >> ai;
        cur_xor ^= ai;
    }
    while (q--) {
        int ai;
        cin >> ai;
        if (n & 1)
            cur_xor ^= ai;
    }
    cout << cur_xor << endl;

    return 0;
}
