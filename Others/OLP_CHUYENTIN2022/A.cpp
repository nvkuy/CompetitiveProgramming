#include <bits/stdc++.h>
using namespace std;

int main() {

    string s;
    cin >> s;
    int n = s.length();
    int max_len_odd = 1, max_len_even = 0;
    for (int i = 0; i < n; i++) {
        int tans = 0;
        for (int j = 1; i + j < n && i - j >= 0; j++) {
            if (s[i + j] == s[i - j])
                tans++;
            else
                break;
        }
        max_len_odd = max(max_len_odd, tans * 2 + 1);
    }
    for (int i = 1; i < n; i++) {
        int tans = 0;
        for (int j = 0; i + j < n && i - j - 1 >= 0; j++) {
            if (s[i + j] == s[i - j - 1])
                tans++;
            else
                break;
        }
        max_len_even = max(max_len_even, tans * 2);
    }
    // cout << max_len_odd << ' ' << max_len_even << endl;
    int q, k, l;
    cin >> q;
    while (q--) {
        cin >> k >> l;
        bool iok = false;
        if (l % 2)
            iok = l <= max_len_odd;
        else
            iok = l <= max_len_even;
        cout << (iok ? "YES" : "NO") << endl;
    }

    return 0;
}