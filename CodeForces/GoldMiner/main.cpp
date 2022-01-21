#include <bits/stdc++.h>

using namespace std;

int main()
{

    string s;
    int k;
    getline(cin, s);
    cin >> k;
    int m1 = 1e9, m2 = 1e9, p1 = -1, p2 = -1;
    for (int i = 0; i < s.length(); i++) {
        if ((int)(s[i]) <= m1) {
            if ((int)(s[i]) == m1) {
                if (i == (s.length() - 1)) {
                    if ((int)(s[i - 1]) >= (int)(s[p2]))
                        continue;
                } else {
                    if (((int)(s[i + 1]) >= (int)(s[p2])) && ((int)(s[i - 1]) >= (int)(s[p2])))
                        continue;
                }
            }
            m1 = (int)s[i];
            p1 = i;
            if (i == 0)
                p2 = i + 1;
            else if (i == (s.length() - 1))
                p2 = i - 1;
            else {
                p2 = i + 1;
                if ((int)(s[p2]) > (int)(s[i - 1]))
                    p2 = i - 1;
            }
            m2 = (int)(s[p2]);
            //cout << p1 << " " << p2 << endl;
        }
    }
    int dr = 1;
    while (k--) {
        if (dr > 0)
            cout << (char)(s[p1]);
        else
            cout << (char)(s[p2]);
        dr = -dr;
    }

    return 0;
}
