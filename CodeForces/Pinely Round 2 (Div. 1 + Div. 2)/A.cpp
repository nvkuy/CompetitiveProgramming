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
        int n, a, q;
        cin >> n >> a >> q;
        string s;
        cin >> s;
        int max_online = a, posible = a, cur = a;
        for (int i = 0; i < q; i++) {
            if (s[i] == '+') {
                posible++;
                cur++;
            } else
                cur--;
            max_online = max(max_online, cur);
        }
        if (max_online >= n) {
            cout << "YES" << endl;
            continue;
        }
        cout << (posible >= n ? "MAYBE" : "NO") << endl;
    }

    return 0;
}
