#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, a, b, p1, p2;
    string s;
    cin >> t;
    cin.ignore();
    while (t--) {
        getline(cin, s);
        p1 = p2 = -1;
        for (int i = 0; i < s.length() - 1; i++) {
            a = s[i] - '0';
            b = s[i + 1] - '0';
            if (a + b > 9)
                p1 = i;
            else {
                if (a + b > a && p2 < 0)
                    p2 = i;
            }
        }
        if (p1 >= 0) {
            a = s[p1] - '0';
            b = s[p1 + 1] - '0';
            for (int i = 0; i < p1; i++)
                cout << s[i];
            cout << to_string(a + b);
            for (int i = p1 + 2; i < s.length(); i++)
                cout << s[i];
        } else {
            if (p2 < 0)
                p2 = s.length() - 2;
            a = s[p2] - '0';
            b = s[p2 + 1] - '0';
            for (int i = 0; i < p2; i++)
                cout << s[i];
            cout << to_string(a + b);
            for (int i = p2 + 2; i < s.length(); i++)
                cout << s[i];
        }
        cout << endl;
    }

    return 0;
}
