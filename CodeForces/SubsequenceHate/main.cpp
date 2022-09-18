#include <bits/stdc++.h>

using namespace std;

int main()
{

    int t, c[1002], ans, cc;
    string s;
    cin >> t;
    cin.ignore();
    while (t--) {
        getline(cin, s);
        c[0] = 0;
        for (int i = 1; i <= s.length(); i++) {
            c[i] = c[i - 1] + (int)(s[i - 1] - '0');
            //cout << c[i];
        }
        //cout << endl;
        ans = 1e9, cc = 1e9;
        for (int i = 0; i <= s.length(); i++) {
            cc = min(c[i], i - c[i]) + min((int)(c[s.length()] - c[i]), (int)(s.length() - i - c[s.length()] + c[i]));
            if (cc < ans)
                ans = cc;
        }
        cout << ans << '\n';
    }

    return 0;
}
