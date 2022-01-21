#include <bits/stdc++.h>

using namespace std;

string s1, s2;

int main()
{

    cin >> s1 >> s2;

    for (int i = 0; i < s1.length(); i++) {
        if (tolower(s1[i]) < tolower(s2[i])) {
            cout << "-1";
            break;
        } else if (tolower(s1[i]) > tolower(s2[i])) {
            cout << "1";
            break;
        } else {
            if (i == s2.length() - 1)
                cout << "0";
        }
    }

    return 0;
}
