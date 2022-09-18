#include <bits/stdc++.h>

using namespace std;

int main()
{

    int t, ans;
    long long n;
    string s;
    cin >> t;
    while (t--) {
        cin >> n;
        s = to_string(n);
        reverse(s.begin(), s.end());
        ans = 20;
        int i = 0, j;
        while (s[i] != '0' && i < s.length())
            i++;
        if (i != s.length()) {
            for (j = i + 1; j < s.length(); j++) {
                if (s[j] == '0' || s[j] == '5')
                    break;
            }
            ans = min(ans, j - 1);
        }
        i = 0;
        while (s[i] != '5' && i < s.length())
            i++;
        if (i != s.length()) {
            for (j = i + 1; j < s.length(); j++) {
                if (s[j] == '2' || s[j] == '7')
                    break;
            }
            ans = min(ans, j - 1);
        }

        cout << ans << endl;
    }

    return 0;
}
