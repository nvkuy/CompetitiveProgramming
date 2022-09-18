#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n;
    string s;
    cin >> t;
    cin.ignore();
    while (t--) {
        getline(cin, s);
        n = s.length();
        if (n % 2) {
            cout << "NO\n";
            continue;
        }
        bool is = true;
        for (int i = 0; i < (n / 2); i++) {
            if (s[i] != s[i + (n / 2)]) {
                is = false;
                break;
            }
        }
        if (is)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
