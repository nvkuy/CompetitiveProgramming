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
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != '?') continue;
            if (i > 0 && s[i - 1] == '0') s[i] = '0';
            else s[i] = '1';
        }
        reverse(s.begin(), s.end());
        cout << s << endl;
    }

    return 0;
}
