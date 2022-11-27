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
    string s;
    cin >> t;
    while (t--) {
        cin >> s;
        bool iok = true;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != 'Y' && s[i] != 'e' && s[i] != 's')
                iok = false;
            if (i == 0)
                continue;
            if (s[i] == 'Y' && s[i - 1] != 's')
                iok = false;
            if (s[i] == 'e' && s[i - 1] != 'Y')
                iok = false;
            if (s[i] == 's' && s[i - 1] != 'e')
                iok = false;
        }
        cout << (iok ? "YES" : "NO") << endl;
    }

    return 0;
}
