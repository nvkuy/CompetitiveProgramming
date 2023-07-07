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

    long long n, k, c;
    cin >> n >> k >> c;
    for (long long add_turn = 1; add_turn <= n; add_turn++) {
        long long loot_turn = n - add_turn;
        long long remain = add_turn + c * add_turn * (add_turn - 1) / 2 - loot_turn;
        if (remain == k) {
            cout << loot_turn << endl;
            return 0;
        }
    }

    return 0;
}
