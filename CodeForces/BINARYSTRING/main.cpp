#include <bits/stdc++.h>

using namespace std;

int main()
{

    int t, c, ans;
    bool fl;
    string s;
    cin >> t;
    while (t > 0) {
        t--;
        cin >> s;
        c = 0;
        ans = 0;
        fl = false;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0') {
                c++;
            } else {
                if (fl)
                    ans += c;
                fl = true;
                c = 0;
            }
        }
        if (fl)
            cout << ans;
        else
            cout << "-1";
        cout << "\n";
    }

    return 0;
}
