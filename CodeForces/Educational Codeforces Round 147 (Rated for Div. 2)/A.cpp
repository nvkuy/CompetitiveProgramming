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

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        if (s[0] == '0') {
            cout << 0 << endl;
            continue;
        }
        int ans = 1;
        if (s[0] == '?') ans *= 9;
        for (int i = 1; i < s.length(); i++)
            if (s[i] == '?') ans *= 10;
        cout << ans << endl;
    }

    return 0;
}
