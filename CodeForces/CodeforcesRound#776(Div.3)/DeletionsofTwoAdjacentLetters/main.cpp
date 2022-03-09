#include <bits/stdc++.h>

using namespace std;

int main()
{

    int t;
    string s;
    char c;
    cin >> t;
    while (t--) {
        cin >> s >> c;
        bool iok = false;
        for (int i = 0; i < s.length(); i++) {
            if ((s[i] == c) && (i % 2 == 0)) {
                iok = true;
                break;
            }
        }
        cout << (iok ? "YES" : "NO") << endl;
    }

    return 0;
}
