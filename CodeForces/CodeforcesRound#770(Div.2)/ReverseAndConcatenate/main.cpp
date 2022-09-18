#include <bits/stdc++.h>

using namespace std;

bool check(string s, int n) {
    for (int i = 0; i < n / 2; i++)
        if (s[i] != s[n - i - 1])
            return false;
    return true;
}

int main()
{
    int t, n, k;
    string s;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        cin.ignore();
        getline(cin, s);
        if (check(s, n))
            cout << "1\n";
        else {
            if (k == 0)
                cout << "1\n";
            else
                cout << "2\n";
        }
    }

    return 0;
}
