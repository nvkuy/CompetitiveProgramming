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

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        long long s1 = 0, s2 = 0;
        while (n--) {
            int ai;
            cin >> ai;
            s1 += ai;
        }
        while (m--) {
            int ai;
            cin >> ai;
            s2 += ai;
        }
        if (s1 == s2) {
            cout << "Draw" << endl;
            continue;
        }
        cout << (s1 > s2 ? "Tsondu" : "Tenzing") << endl;
    }

    return 0;
}
