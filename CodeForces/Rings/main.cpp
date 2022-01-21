#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n;
    string s, tmp;
    cin >> t;
    while (t--) {
        cin >> n;
        cin.ignore();
        getline(cin, s);
        tmp.clear();
        for (int i = 0; i < (n / 2); i++)
            tmp.push_back('0');
        int j = s.find(tmp);
        if (j >= 0) {
            cout << j + 1 << ' ' << j + (n / 2) << " 1 " << n << endl;
            continue;
        }
        j = 0;
        for (int i = 0; i < n; i++)
            if (s[i] == '1')
                j++;
        if (j == n) {
            cout << "1 " << n / 2 << " 2 " << (n / 2) + 1 << endl;
            continue;
        }
        j = -1;
        for (int i = (n / 2) - 1; i >= 0; i--) {
            if (s[i] == '0') {
                j = i;
                break;
            }
        }
        if (j >= 0) {
            cout << j + 1 << ' ' << n << ' ' << j + 2 << ' ' << n << endl;
            continue;
        }
        for (int i = n / 2; i < n; i++) {
            if (s[i] == '0') {
                j = i;
                break;
            }
        }
        if (j >= 0) {
            cout << "1 " << j + 1 << " 1 " << j << endl;
            continue;
        }
    }

    return 0;
}
