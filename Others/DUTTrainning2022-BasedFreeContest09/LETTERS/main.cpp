#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, ans;
    string s;
    cin >> n;
    cin >> s;
    ans = 0;
    if (s[0] == '?')
        s[0] = 'a';
    for (int i = 1; i < n; i++) {
        if (s[i] != '?')
            continue;
        s[i] = 'b';
    }
    for (int i = 1; i < n; i++) {
        if (s[i - 1] == 'a') {
            if (s[i] != 'a')
                ans++;
        } else {
            if (s[i] != 'b')
                ans--;
        }
    }
    cout << ans;

    return 0;
}
