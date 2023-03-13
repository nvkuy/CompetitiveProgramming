#include <bits/stdc++.h>
using namespace std;

int cal(string s) {
    bool hasAns = false;
    int n = s.length();
    for (int i = 1; i + 1 < n; i++) {
        if (s[i] == 'O') {
            hasAns = true;
            break;
        }
    }
    if (!hasAns) return -1;
    for (int i = 0; i + 2 < n; i++)
        if (s[i] == 'M' && s[i + 1] == 'O' && s[i + 2] == 'O')
            return n - 3;
    for (int i = 1; i + 1 < n; i++) {
        if (s[i] == 'O' && s[i + 1] == 'O')
            return n - 2;
    }
    for (int i = 0; i + 2 < n; i++) {
        if (s[i] == 'M' && s[i + 1] == 'O')
            return n - 2;
    }
    return n - 1;
}

int main() {

    int q;
    cin >> q;
    while (q--) {
        string s;
        cin >> s;
        cout << cal(s) << endl;
    }

    return 0;
}