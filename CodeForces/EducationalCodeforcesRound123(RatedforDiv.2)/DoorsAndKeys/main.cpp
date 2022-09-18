#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    bool dd[202];
    string s;
    cin >> t;
    cin.ignore();
    while (t--) {
        memset(dd, false, sizeof(dd));
        getline(cin, s);
        bool iok = true;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'R') {
                if (!dd['r']) {
                    iok = false;
                    break;
                }
            }
            if (s[i] == 'B') {
                if (!dd['b']) {
                    iok = false;
                    break;
                }
            }
            if (s[i] == 'G') {
                if (!dd['g']) {
                    iok = false;
                    break;
                }
            }
            dd[s[i]] = true;
        }
        cout << (iok ? "YES" : "NO") << endl;
    }

    return 0;
}
