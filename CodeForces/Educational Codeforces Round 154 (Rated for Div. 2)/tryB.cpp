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
        string a, b;
        cin >> a >> b;
        bool iok = false;
        for (int i = 0; i + 1 < a.length(); i++) {
            if (a[i] != '0' || b[i] != '0') continue;
            if (a[i + 1] != '1' || b[i + 1] != '1') continue;
            iok = true;
            break;
        }
        cout << (iok ? "YES" : "NO") << endl;
    }

    return 0;
}
