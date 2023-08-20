#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'
#define bit_cnt(x) __builtin_popcountll(x)

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int pos1 = -1, posn = -1, pos2 = -1;
        for (int i = 1; i <= n; i++) {
            int ai;
            cin >> ai;
            if (ai == 1)
                pos1 = i;
            if (ai == 2)
                pos2 = i;
            if (ai == n)
                posn = i;
        }
        if (min(pos2, posn) < pos1 && pos1 < max(pos2, posn))
            cout << pos1 << ' ' << posn << endl;
        else {
            if (abs(posn - pos1) > abs(pos2 - pos1))
                cout << posn << ' ' << pos2 << endl;
            else
                cout << 1 << ' ' << 1 << endl;
        }
    }

    return 0;
}
