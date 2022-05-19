#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n;
    string s1, s2;
    cin >> t;
    while (t--) {
        cin >> n;
        cin.ignore();
        getline(cin, s1), getline(cin, s2);
        int st = n, ed = -1;
        for (int i = 0; i < n; i++) {
            if (s1[i] == '*' || s2[i] == '*') {
                st = min(st, i);
                ed = i;
            }
        }
        int pf1 = -1, pf2 = -1, f1, f2;
        for (int i = st ; i <= ed; i++) {
            pf1 = min(pf1, pf2 + 1), pf2 = min(pf2, pf1 + 1);
            if (s1[i] == '*' && s2[i] == '*') {
                f1 = min(pf2 + 2, pf1 + 2), f2 = min(pf2 + 2, pf1 + 2);
                pf1 = f1, pf2 = f2;
                continue;
            }
            if (s1[i] == '.' && s2[i] == '.') {
                pf1++, pf2++;
                continue;
            }
            if (s1[i] == '*') {
                f1 = min(pf1 + 1, pf2 + 2), f2 = min(pf2 + 2, pf1 + 2);
                pf1 = f1, pf2 = f2;
            }
            if (s2[i] == '*') {
                f1 = min(pf1 + 2, pf2 + 2), f2 = min(pf2 + 1, pf1 + 2);
                pf1 = f1, pf2 = f2;
            }
        }
        cout << min(f1, f2) << endl;
    }

    return 0;
}
