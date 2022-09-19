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
    cin.ignore();
    while (t--) {
        getline(cin, s);
        int open_cnt = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(')
                open_cnt++;
        }
        int need_open = (s.length() / 2) - open_cnt;
        int p1 = -1, p2 = -1;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != '?')
                continue;
            if (need_open == 1)
                p1 = i;
            if (need_open == 0)
                p2 = i;
            if (need_open > 0)
                s[i] = '(';
            else
                s[i] = ')';
            need_open--;
        }
        if (p1 >= 0 && p2 >= 0)
            swap(s[p1], s[p2]);
        // cout << "change to " << s << endl;
        // cout << p1 << '|' << p2 << endl;
        int cs = 0, iok = 1;
        for (int i = 0; i < s.length(); i++) {
            cs += (s[i] == '(' ? 1 : -1);
            if (cs < 0)
                iok = 0;
        }
        if (p1 < 0 || p2 < 0)
            iok = 0;
        cout << ((iok == 0) ? "YES" : "NO") << endl;
    }

    return 0;
}