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
        deque<int> pos;
        int cs = 0, qc;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '?')
                pos.push_back(i);
            else
                cs += (s[i] == '(' ? 1 : -1);
        }
        if (cs > 0) {
            for (int i = 0; i < cs; i++) {
                s[pos.back()] = ')';
                pos.pop_back();
            }
        } else {
            cs = -cs;
            for (int i = 0; i < cs; i++) {
                s[pos.front()] = '(';
                pos.pop_front();
            }
        }
        qc = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '?')
                qc++;
        }
        bool iok = (qc < 4);
        cs = 0, qc = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '?')
                qc++;
            else
                cs += (s[i] == '(' ? 1 : -1);
            if (cs == 0) {
                if (s[i] == '?' && qc > 1)
                    qc -= 2;
            }
            if (cs < 0 || i + 1 == s.length()) {
                if (cs < 0)
                    qc--;
                else
                    qc -= cs;
                if (qc > 1)
                    iok = false;
                cs = 0;
            }
        }
        cout << (iok ? "YES" : "NO") << endl;
    }

    return 0;
}