#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    string s;
    cin >> t;
    cin.ignore();
    while (t--) {
        s.clear();
        getline(cin, s);
        sort(s.begin(), s.end());
        cout << s << endl;
    }

    return 0;
}
