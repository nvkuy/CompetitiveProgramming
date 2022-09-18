#include <bits/stdc++.h>

using namespace std;

int main()
{
    int q;
    string s, t;
    cin >> q;
    cin.ignore();
    while (q--) {
        getline(cin, s);
        getline(cin, t);
        int i = s.length() - 1, j = t.length() - 1, c = 0;;
        while (true) {
            if (s[i] != t[j])
                c++;
            else {
                if (c % 2 == 0) {
                    j--;
                    c = 0;
                    if (j < 0)
                        break;
                } else
                    c++;
            }
            i--;
            if (i < 0)
                break;
        }
        cout << ((j < 0) ? "YES" : "NO") << '\n';
    }

    return 0;
}
