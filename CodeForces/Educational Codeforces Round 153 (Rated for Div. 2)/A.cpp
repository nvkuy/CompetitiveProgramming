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

bool iok(string s, string p) {
    for (int i = 0; i < s.length(); i++) {
        if (i + p.length() - 1 >= s.length()) break;
        if (s.substr(i, p.length()) == p) return false;
    }
    return true;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        string s1, s2;
        for (int i = 0; i < s.length(); i++) {
            s1.push_back('(');
            s2 += "()";
        }
        for (int i = 0; i < s.length(); i++)
            s1.push_back(')');
        if (iok(s1, s))
            cout << "YES" << endl << s1 << endl;
        else if (iok(s2, s))
            cout << "YES" << endl << s2 << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
