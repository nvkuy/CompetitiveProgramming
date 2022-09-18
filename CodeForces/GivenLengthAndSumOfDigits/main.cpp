#include <bits/stdc++.h>

using namespace std;

int main()
{
    int m, s, n, r;
    string ans;
    cin >> m >> s;

    if (m == 1 && s == 0) {
        cout << "0 0";
        return 0;
    }
    if (((9 * m) < s) || (s < 1 && m > 1))
        cout << "-1 -1";
    else {
        //min
        n = s / 9;
        if (s % 9 > 0)
            ans += to_string(s % 9);
        r = m - n - (s % 9 > 0);
        for (int i = 0; i < r; i++)
            ans = '0' + ans;
        for (int i = 0; i < n; i++)
            ans += '9';
        ans[0] = (char)(((int)ans[0]) + 1); ans[r] = (char)(((int)ans[r]) - 1);
        cout << ans << " ";
        ans.clear();
        //max
        n = s / 9;
        r = m - n - (s % 9 > 0);
        for (int i = 0; i < n; i++)
            ans += '9';
        if (s % 9 > 0)
            ans += to_string(s % 9);
        for (int i = 0; i < r; i++)
            ans += '0';
        cout << ans;
    }

    return 0;
}
