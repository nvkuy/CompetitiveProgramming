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

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int odd_cnt = 0, ai;
        for (int i = 0; i < n; i++) {
            cin >> ai;
            odd_cnt += (abs(ai) % 2);
        }
        if (((odd_cnt % 4) == 1 && ((n - odd_cnt) % 2 == 0)) || (odd_cnt % 4) == 2)
            cout << "Bob";
        else
            cout << "Alice";
        cout << endl;
    }

    return 0;
}