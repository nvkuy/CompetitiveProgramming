#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n;
    char c;
    string s;
    cin >> t;
    while (t--) {
        cin >> n >> c;
        cin.ignore();
        getline(cin, s);
        for (int i = 0; i < s.length(); i++)
            if (s[i] == c)
                n--;
        if (n <= 0) {
            cout << "0\n";
            continue;
        }
        n = 0;
        for (int i = (s.length() / 2); i < s.length(); i++) {
            if (s[i] == c) {
                n = i + 1;
                break;
            }
        }
        if (n > 0)
            cout << "1\n" << n << '\n';
        else
            cout << "2\n" << s.length() - 1 << ' ' << s.length() << '\n';
    }

    return 0;
}
