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
        if (s.find("aa") != -1) {
            cout << "2\n";
            continue;
        }
        if ((s.find("aba") != -1) || (s.find("aca") != -1)) {
            cout << "3\n";
            continue;
        }
        if ((s.find("abca") != -1) || (s.find("acba") != -1)) {
            cout << "4\n";
            continue;
        }
        if ((s.find("abbacca") != -1) || (s.find("accabba") != -1)) {
            cout << "7\n";
            continue;
        }
        cout << "-1\n";
    }

    return 0;
}
