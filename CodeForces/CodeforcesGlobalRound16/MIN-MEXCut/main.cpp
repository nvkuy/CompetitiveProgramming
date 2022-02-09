#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, ans;
    string s;
    cin >> t;
    cin.ignore();
    while (t--) {
        getline(cin, s);
        ans = 0;
        int i = 0;
        while (i < s.length()) {
            if (s[i] == '1') {
                i++;
                continue;
            }
            ans++;
            if (ans > 2) {
                ans = 2;
                break;
            }
            for (int j = i; j < s.length(); j++) {
                if (s[j] != '0')
                    break;
                i++;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
