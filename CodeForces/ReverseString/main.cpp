#include <bits/stdc++.h>

using namespace std;

bool test(int i, int j, string s, string t, int dr) {
    bool iok = false;
    while (s[i] == t[j]) {
        i += dr;
        j++;
        if (i == s.length() && j < t.length())
            iok |= test(i - 2, j, s, t, -dr);
        if (iok)
            return true;
        if (j >= t.length() || i >= s.length() || i < 0)
            break;
        if (dr > 0 && i >= 2)
            iok |= test(i - 2, j, s, t, -dr);
        if (iok)
            return true;
    }
    return j >= t.length();
}

int main()
{
    int q;
    string s, t;
    cin >> q;
    cin.ignore();
    while (q--) {
        s.clear(); t.clear();
        getline(cin, s);
        getline(cin, t);
        bool iok = false;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == t[0])
                iok |= test(i, 0, s, t, 1);
            if (iok)
                break;
        }
        cout << (iok ? "YES" : "NO") << endl;
    }

    return 0;
}
