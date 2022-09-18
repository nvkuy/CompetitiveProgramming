#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n;
    string s1, s2;
    cin >> t;
    while (t--) {
        cin >> n;
        cin.ignore();
        getline(cin, s1);
        getline(cin, s2);
        int ans = 0, i = 0;
        while (i < s1.length()) {
            int a = s1[i] - '0', b = s2[i] - '0';
            if (a + b == 1) {
                ans += 2;
                i++;
                continue;
            }
            if (a + b == 2) {
                i++;
                if (i == s1.length())
                    continue;
                if (s1[i] == '1' && s2[i] == '1')
                    continue;
                ans += 2;
                i++;
            }
            if (a + b == 0) {
                ans++;
                i++;
                if (i == s1.length())
                    continue;
                if (s1[i] != '1' || s2[i] != '1')
                    continue;
                ans++;
                i++;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
