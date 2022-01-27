#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, m;
    string s;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        cin.ignore();
        getline(cin, s);
        int x = 0, y = 0;
        int lm = 0, rm = 0, um = 0, dm = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'L')
                y--;
            else if (s[i] == 'R')
                y++;
            else if (s[i] == 'U')
                x--;
            else
                x++;
            lm = min(lm, y);
            rm = max(rm, y);
            um = min(um, x);
            dm = max(dm, x);

            if (rm - lm >= m) {
                if (lm == y)
                    lm++;
                break;
            }
            if (dm - um >= n) {
                if (um == x)
                    um++;
                break;
            }

        }
        cout << 1 - um << ' ' << 1 - lm << endl;
    }

    return 0;
}
