#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    string s;
    cin >> t;
    cin.ignore();
    while (t--) {
        getline(cin, s);
        int a = 0, b = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0')
                a++;
            else
                b++;
        }
        if (s.length() == 1) {
            cout << "0\n";
            continue;
        }
        if (a == b)
            cout << a - 1 << endl;
        else if (a > b)
            cout << b << endl;
        else
            cout << a << endl;
    }

    return 0;
}
