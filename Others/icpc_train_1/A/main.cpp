#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

bool checkPos(int pos, string &s, string &t) {
    for (int i = 0; i < pos; i++)
        if (i >= t.length() || s[i] != t[i])
            return false;
    int i1 = s.length() - 1, i2 = t.length() - 1;
    while (i1 != pos) {
        if (i2 < pos || s[i1] != t[i2])
            return false;
        i1--, i2--;
    }
    return true;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    string t, s;
    cin >> n;
    cin >> s;
    for (char &c : s)
        c = tolower(c);
    for (int i = 0; i < n; i++) {
        cin >> t;
        for (char &c : t)
            c = tolower(c);
        bool iok = false;
        for (int i = 1; i + 1 < s.length(); i++) {
            if (s[i] == '*')
                iok |= checkPos(i, s, t);
        }
        iok &= (s != t);
        cout << (iok ? "YES" : "NO") << endl;
    }

    return 0;
}
