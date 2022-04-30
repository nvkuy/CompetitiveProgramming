#include <bits/stdc++.h>

using namespace std;

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
        vector<bool> isInS(33, false);
        for (int i = 0; i < s.length(); i++)
            isInS[s[i] - 'a'] = true;
        vector<int> nearest(33, -1);
        bool iok = true;
        for (int i = 0; i < s.length(); i++) {
            if (!iok)
                break;
            if (nearest[s[i] - 'a'] < 0) {
                nearest[s[i] - 'a'] = i;
                continue;
            }
            for (int j = 0; j < 33; j++) {
                if (isInS[j] && nearest[j] < nearest[s[i] - 'a']) {
                    iok = false;
                    break;
                }
            }
            nearest[s[i] - 'a'] = i;
        }
        cout << (iok ? "YES" : "NO") << endl;
    }

    return 0;
}
