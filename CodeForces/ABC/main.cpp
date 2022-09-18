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
        getline(cin, s);
        int c1 = 0, c2 = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0')
                c1++;
            else
                c2++;
        }
        cout << ((c1 <= 1 && c2 <= 1) ? "YES" : "NO") << '\n';
    }

    return 0;
}
