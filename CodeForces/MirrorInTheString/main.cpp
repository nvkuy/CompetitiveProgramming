#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n;
    string s;
    cin >> t;
    while (t--) {
        cin >> n;
        cin.ignore();
        s.clear();
        getline(cin, s);
        int i = 0, co = 0;
        while (i < (n - 1)) {
            i++;
            if (s[i] > s[i - 1]) {
                i--;
                break;
            }
            if (s[i] == s[i - 1]) {
                co++;
                if (i - co - 1 < 0) {
                    i -= co;
                    break;
                }
                if (s[i - co - 1] <= s[i]) {
                    i -= co;
                    break;
                }
            }
        }
        for (int j = 0; j <= i; j++)
            cout << s[j];
        while (i >= 0) {
            cout << s[i];
            i--;
        }
        cout << endl;
    }

    return 0;
}
