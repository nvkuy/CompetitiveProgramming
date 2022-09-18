#include <bits/stdc++.h>

using namespace std;

int n;
string s;

int main()
{

    cin >> n;
    while (n > 0) {
        cin >> s;
        if (s.length() > 10) {
            cout << s[0] << s.length() - 2 << s[s.length() - 1] << "\n";
        } else
            cout << s << "\n";
        n--;
    }

    return 0;
}
