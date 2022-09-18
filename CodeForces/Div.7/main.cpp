#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, tmp;
    string s;
    cin >> t;
    cin.ignore();
    while (t--) {
        getline(cin, s);
        n = stoi(s);
        tmp = n % 7;
        if (tmp == 0)
            cout << n << endl;
        else {
            if ((n % 10) - tmp >= 0)
                n -= tmp;
            else
                n += (7 - tmp);
            cout << n << endl;
        }
    }

    return 0;
}
